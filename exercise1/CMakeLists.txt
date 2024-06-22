add_library(DayOfYear SHARED src/day-of-year.cpp)
target_include_directories (DayOfYear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(DayOfYearTest ut/day-of-year-tests.cpp)
target_include_directories (DayOfYear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(DayOfYearTest PUBLIC DayOfYear)
target_link_libraries(DayOfYearTest PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(DayOfYearTest)
