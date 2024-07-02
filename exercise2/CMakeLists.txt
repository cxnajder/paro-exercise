set(SBRABBLE_SOURCE_LIB scrabbleScore)
add_library(${SBRABBLE_SOURCE_LIB} SHARED src/${SBRABBLE_SOURCE_LIB}.cpp)
target_include_directories (${SBRABBLE_SOURCE_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
