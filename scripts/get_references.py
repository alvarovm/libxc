#!/usr/bin/env python3

# Copyright (C) 2021 M.A.L. Marques
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

import re, sys
from pybtex.database import BibliographyData, parse_file
from pybtex.backends.plaintext import Backend
from pybtex.style.formatting import toplevel
from pybtex.style.template import (
    field, first_of, href, join, names, optional, optional_field, sentence,
    tag, together, words
)
from pybtex.style.formatting.unsrt import pages, dashify, Style as UnsrtStyle
from pybtex.database.output.bibtex import Writer as BibWriter

class LibxcStyle(UnsrtStyle):
  '''This is the definition of our bibliography style
  It is considerably simpler than unsrt'''
  def get_article_template(self, e):
    volume_and_pages = first_of [
      optional [ join [ tag('b') [field('volume')], ', ', pages ], ],
      words ['pages', pages],
    ]
    template = toplevel [
      join [ self.format_names('author'), ", " ],
      join [
        tag('em') [field('journal')],
        " ", optional[ volume_and_pages ],
        " (", field('year'), ")"
      ],
    ]
    return template

    def format_web_refs(self, e):
      # we just leave the doi
      return optional[ join ['doi:', field('doi', raw=True)] ]

class LibxcWriter(BibWriter):
  def quote(self, s):
    '''We change the quotes to braces that are better suited for libxc'''
    self.check_braces(s)
    return '{%s}' % s

  def _write_field(self, stream, type, value):
    '''We prefer two spaces instead of four'''
    stream.write(u',\n  %s = %s' % (type, self.quote(self._encode(value))))

    
# Code starts here
if len(sys.argv) != 2:
  print(f"Usage: {sys.argv[0]} BIBFILE\n")
  sys.exit(1)

# Load bibtex file
bib_data = parse_file(sys.argv[1])

# format bibliography
style = LibxcStyle(abbreviate_names=True)
formatted_bibliography = style.format_bibliography(bib_data, "*")

# write files
header = '''/*
   This file is autogenerated. Please do not change it directly. Run instead
   ./scripts/get_references.py
*/

/*
 Copyright (C) 2006-2021 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include <xc.h>

'''

fh_c = open("references.c", "w")
fh_h = open("references.h", "w")

fh_c.write(header)
fh_h.write(header)

backend = Backend()
writer  = LibxcWriter()
for item in formatted_bibliography:
  # we get the doi for the references that have it
  if "doi" in bib_data.entries[item.key].fields:
    doi = bib_data.entries[item.key].fields["doi"]
  else:
    doi = ""

  # to get the bibtex we need to struggle a little
  # first we construct a BibliographyData with an unique entry
  # and we use to_string to get the text
  _bibdata = BibliographyData(entries={item.key: bib_data.entries[item.key]})
  bibtex = writer.to_string(_bibdata)

  # we have to quote a couple of things to generate valid C code
  bibtex = bibtex.replace('\\', '\\\\')
  bibtex = bibtex.replace('\n', '\\n')
  bibtex = bibtex.replace('"', '\\"')

  # now we write the files
  fh_c.write('func_reference_type xc_ref_' + item.key + ' = {\n' +
             '  "' + item.text.render(backend) + '",\n' +
             '  "' + doi + '",\n' +
             '  "' + bibtex + '",\n' +
             '  "' + item.key + '"\n' +
             '};\n\n'
             )
  fh_h.write('extern func_reference_type xc_ref_' + item.key + ';\n')

fh_c.close()
fh_h.close()
