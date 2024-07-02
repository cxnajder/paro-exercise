set (SBRABBLE_SCORE_LIB scrabbleScore)
add_library (${SBRABBLE_SCORE_LIB} SHARED src/${SBRABBLE_SCORE_LIB}.cpp)
target_include_directories (${SBRABBLE_SCORE_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


set (SBRABBLE_SCORE_TEST ${SBRABBLE_SCORE_LIB}Tests)
add_executable (${SBRABBLE_SCORE_TEST} ut/${SBRABBLE_SCORE_TEST}.cpp)
target_include_directories (${SBRABBLE_SCORE_TEST} 
    PUBLIC ../external/googletest/googletest/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries (${SBRABBLE_SCORE_TEST} 
    PRIVATE gtest gtest_main 
    PRIVATE ${SBRABBLE_SCORE_LIB}
)