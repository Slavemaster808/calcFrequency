set(target_name calcfreq)

add_library(${target_name} STATIC
  libcalcfreq/funcs.cpp
  libcalcfreq/funcs.hpp)

include(CompileOptions)
set_compile_options(${target_name})

target_include_directories(
  ${target_name}
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)