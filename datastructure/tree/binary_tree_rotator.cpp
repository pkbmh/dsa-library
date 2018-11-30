//
// Created by Pankaj Birat on 30/11/18.
//
#include "tree_node.hpp"

template <class K, class V>
class binary_tree_rotator {
public:
    /*         a                 b
     *      b    t1   --->   c       a
     *    c   t2          t3  t4  t2   t1
     * t3   t4
     */
    static tree_node<K,V>* right_rotate(tree_node<K,V> *node);

    /*        a                          b
     *    t1     b         --->      a       c
     *       t2     c             t1   t2  t3  t4
     *           t3   t4
     */
    static tree_node<K,V>* left_rotate(tree_node<K,V> *node);
};

template <class K, class V>
tree_node<K,V>* binary_tree_rotator<K,V>::right_rotate(tree_node<K, V> *node) {
    tree_node<K,V>*tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    tree_node<K,V>::size_height_reset(node);
    tree_node<K,V>::size_height_reset(tmp);
    return tmp;
}

template <class K, class V>
tree_node<K,V>* binary_tree_rotator<K,V>::left_rotate(tree_node<K, V> *node) {
    tree_node<K,V> *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    tree_node<K,V>::size_height_reset(node);
    tree_node<K,V>::size_height_reset(tmp);
    return tmp;
}