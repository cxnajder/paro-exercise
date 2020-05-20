add_library(DayOfYear STATIC
  src/day-of-year.cpp
)

target_include_directories (DayOfYear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
