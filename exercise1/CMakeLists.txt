add_library(DayOfYear SHARED src/dayOfYear.cpp)
target_include_directories (DayOfYear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(DayOfYearTests ut/dayOfYearTests.cpp)
target_include_directories (DayOfYear PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(DayOfYearTests PUBLIC DayOfYear)
target_link_libraries(DayOfYearTests PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(DayOfYearTests)
