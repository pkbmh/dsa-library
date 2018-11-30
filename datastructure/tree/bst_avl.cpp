//
// Created by Pankaj Birat on 30/11/18.
//
#pragma once
#include "binary_search_tree.cpp"
#include "binary_tree_rotator.cpp"

template <class K, class V>
class bst_avl : public binary_search_tree<K,V> {
private:
    tree_node<K,V>* insert(tree_node<K,V> * node, K key, V value);
};

template <class K, class V>
tree_node<K,V>* bst_avl<K,V>::insert(tree_node<K, V> *node, K key, V value) {
    node = binary_search_tree<K,V>::insert(node, key, value);
    int height_diff = tree_node<K,V>::getNodeHeight(node->left) - tree_node<K,V>::getNodeHeight(node->right);

    /*
     * left left unbalanced case
     *       a                          b
     *     b      right rotate ->     c   a
     *   c
     *   >= because we used >= while inserting
     */
    if(height_diff >= 2 && node->left->data >= value) {
        node = binary_tree_rotator<K,V>::right_rotate(node);
    }

    /*
     * left right unbalanced case
     *      a                                 a                                             b
     *    b       left rotate from b --->    b      (left left case : right rotate) ---> c   a
     *      c                             c
     */
    if(height_diff >= 2 && node->left->data < value) {
        node->left = binary_tree_rotator<K,V>::left_rotate(node->left);
        node = binary_tree_rotator<K,V>::right_rotate(node);
    }

    /*
     * right left case
     *     a                               a                                              b
     *       b  right rotate from b --->     b      right right case left rotate --->   a   c
     *     c                                   c
     */
    if(height_diff <= -2 && node->right->data > value) {
        node->right = binary_tree_rotator<K,V>::right_rotate(node->right);
        node = binary_tree_rotator<K,V>::left_rotate(node);
    }

    /*
     *  right right unbalanced case
     *   a                                b
     *     b         left rotate --->   a   c
     *       c
     */
    if(height_diff <= -2 && node->right->data < value) {
        node = binary_tree_rotator<K,V>::left_rotate(node);
    }
    return node;
}
