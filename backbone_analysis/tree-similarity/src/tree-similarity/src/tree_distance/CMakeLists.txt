set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

FIND_PACKAGE( Boost 1.40 COMPONENTS regex REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

# Build executable for out tool.
add_executable(
    tree_distance    # EXECUTABLE NAME
    main.cpp # EXECUTABLE SOURCE
)

# Let the compiler know to find the header files in TreeSimilarity library.
target_link_libraries(
    tree_distance LINK_PUBLIC
    TreeSimilarity
    ${Boost_LIBRARIES}
)