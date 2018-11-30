cmake_minimum_required(VERSION 3.12)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA main.cpp common/common_functions.h test/datastructure/array/custom_array_test.cpp datastructure/list/custom_list.h common/list_exceptions.h datastructure/list/list_node.cpp datastructure/list/list_iterator.cpp datastructure/list/custom_list.cpp test/datastructure/list/custom_list_test.cpp datastructure/printable.h algorithms/lru_cache.cpp test/algorithms/lru_cache_test.cpp test/datastructure/stack/stack_test.cpp test/datastructure/queue/queue_test.cpp datastructure/tree/binary_search_tree.cpp datastructure/tree/binary_search_tree.hpp datastructure/tree/tree_node.hpp datastructure/tree/tree_traverser.cpp test/datastructure/tree/binary_search_tree_test.cpp datastructure/tree/avl_tree.cpp test/datastructure/tree/avl_tree_test.cpp datastructure/tree/binary_tree_rotator.cpp)