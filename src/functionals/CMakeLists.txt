set(SOURCES_dir)

file(GLOB_RECURSE SOURCES_dir
  "*.c"
  )

set(SOURCES ${SOURCES_dir} PARENT_SCOPE)
