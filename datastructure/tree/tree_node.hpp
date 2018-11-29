//
// Created by Pankaj Birat on 29/11/18.
//

#ifndef DSA_TREE_NODE_H
#define DSA_TREE_NODE_H

#include "../../common/headers.h"

template <class K, class V>
struct tree_node {
    K key;
    V data;
    tree_node<K,V> *left;
    tree_node<K, V> *right;
    int size;
    int height;

    static tree_node<K,V>* new_node(K key, V data){
        tree_node<K,V> *tmp = new tree_node;
        tmp->key = key;
        tmp->data = data;
        tmp->left = null;
        tmp->right = null;
        tmp->size = 1;
        tmp->height = 0;
    }
};


#endif //DSA_TREE_NODE_H
