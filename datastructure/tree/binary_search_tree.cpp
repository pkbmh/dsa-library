//
// Created by Pankaj Birat on 29/11/18.
//

#include "binary_search_tree.hpp"

template <class K, class V>
int binary_search_tree<K,V>::getSize() {
    return tree_node<K,V>::getNodeSize(root);
}

template <class K, class V>
int binary_search_tree<K,V>::getHeight() {
    return tree_node<K,V>::getNodeHeight(root);
}

template <class K, class V>
tree_node<K,V> * binary_search_tree<K,V>::rightMostNode(tree_node<K,V> * tmp) {
    while(tmp != null && tmp->right != null) {
        tmp = tmp->right;
    }
    return tmp;
}

template <class K, class V>
tree_node<K,V> * binary_search_tree<K,V>::leftMostNode(tree_node<K, V> *tmp) {
    while(tmp != null && tmp->left != null) {
        tmp = tmp->left;
    }
    return tmp;
}

template <class K, class V>
pair<K,V> binary_search_tree<K,V>::getMax() {
    if(root == null) return DUMMY_KV_PAIR;
    tree_node<K,V> *tmp = rightMostNode(root);
    return {tmp->key, tmp->data};
}

template <class K, class V>
pair<K,V> binary_search_tree<K,V>::getMin() {
    if(root == null) return DUMMY_KV_PAIR;
    tree_node<K,V> *tmp = leftMostNode(root);
    return {tmp->key, tmp->data};
}

template <class K, class V>
void binary_search_tree<K,V>::insert(K key, V value) {
    root = insert(root, key, value);
}

template <class K, class V>
tree_node<K,V>* binary_search_tree<K,V>::insert(tree_node<K,V> * node, K key, V value) {
    if(node == null) {
        return tree_node<K,V>::new_node(key, value);
    }
    if(node->key >= key) {
        node->left = insert(node->left, key, value);
    }else {
        node->right = insert(node->right, key, value);
    }
    tree_node<K, V>::size_height_reset(node);
    return node;
}