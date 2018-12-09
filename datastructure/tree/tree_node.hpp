//
// Created by Pankaj Birat on 29/11/18.
//

#ifndef DSA_TREE_NODE_H
#define DSA_TREE_NODE_H

#include "../../common/headers.hpp"

template <class K, class V>
struct tree_node {
    K key;
    V data;
    tree_node<K,V> *left;
    tree_node<K, V> *right;
    int size;
    int height;

    static int getNodeHeight(tree_node<K,V>*node){
        return node != null ? node->height : 0;
    }
    static int getNodeSize(tree_node<K,V> *node){
        return (node != null) ? node->size : 0;
    }

    static void size_reset(tree_node<K,V> *node) {
        node->size = tree_node<K,V>::getNodeSize(node->left) + tree_node<K,V>::getNodeSize(node->right) + 1;
    }

    static void height_reset(tree_node<K,V> *node) {
        node->height = max(tree_node<K,V>::getNodeHeight(node->left), tree_node<K,V>::getNodeHeight(node->right)) + 1;
    }

    static void size_height_reset(tree_node<K,V> *node) {
        size_reset(node);
        height_reset(node);
    }

    static tree_node<K,V>* new_node(K key, V data){
        auto *tmp = new tree_node;
        tmp->key = key;
        tmp->data = data;
        tmp->left = null;
        tmp->right = null;
        tmp->size = 1;
        tmp->height = 1;
        return tmp;
    }
};


#endif //DSA_TREE_NODE_H
