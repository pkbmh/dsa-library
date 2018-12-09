//
// Created by Pankaj Birat on 30/11/18.
//

#pragma once
#include "binary_search_tree.cpp"
#include "binary_tree_rotator.cpp"

template <class K, class V>
class bst_red_black : public binary_search_tree<K,V> {
private:
    tree_node<K,V>* insert(tree_node<K,V> * node, K key, V value);
};

template <class K, class V>
tree_node<K,V>* bst_red_black<K,V>::insert(tree_node<K, V> *node, K key, V value) {
    node = binary_search_tree<K, V>::insert(node, key, value);
    int height_diff = tree_node<K, V>::getNodeHeight(node->left) - tree_node<K, V>::getNodeHeight(node->right);
    //  TODO implementation
}