set (DAY_Of_YEAR_LIB DayOfYear)
add_library (${DAY_Of_YEAR_LIB} SHARED src/${DAY_Of_YEAR_LIB}.cpp)
target_include_directories (${DAY_Of_YEAR_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set (DAY_Of_YEAR_TEST ${DAY_Of_YEAR_LIB}Tests)
add_executable (${DAY_Of_YEAR_TEST} ut/${DAY_Of_YEAR_TEST}.cpp)

target_include_directories (${DAY_Of_YEAR_TEST}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ../external/googletest/googletest/include
)
target_link_libraries (${DAY_Of_YEAR_TEST} 
    PUBLIC ${DAY_Of_YEAR_LIB}
    PRIVATE PRIVATE gtest gtest_main
)