cmake_minimum_required ( VERSION 3.10.2 )
project(BinaryTree)

add_library(BinaryTreeModule
  Tree.cpp
)

add_executable(Balance Balancing.cpp) 
add_executable(Traverse Traverse.cpp)
add_executable(Morris MorrisComparison.cpp)
add_executable(DSW BalancingDSW.cpp)

target_link_libraries(Balance BinaryTreeModule)
target_link_libraries(Traverse BinaryTreeModule)
target_link_libraries(Morris BinaryTreeModule)
target_link_libraries(DSW BinaryTreeModule)