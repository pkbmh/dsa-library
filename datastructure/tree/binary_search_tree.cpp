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

template <class K, class V>
pair<K, V> binary_search_tree<K,V>::find(K key) {
    tree_node<K,V> *ptr = root;
    while(ptr != null) {
        if(ptr->key == key) return {ptr->key, ptr->data};
        if(ptr->key > key) ptr = ptr->left;
        else if(ptr->key < key) ptr = ptr->right;
    }
    return DUMMY_KV_PAIR;
}
template <class K, class V>
pair<K, V> binary_search_tree<K,V>::ceil(K key) {
    tree_node<K,V> *ptr = root;
    tree_node<K,V> *ans = null;
    while(ptr != null) {
        if(ptr->key == key) {ans = ptr; break;}
        if(ptr->key > key) {ans = ptr; ptr = ptr->left;}
        else if(ptr->key < key) ptr = ptr->right;
    }
    return (ans == null) ? DUMMY_KV_PAIR : MP(ans->key, ans->data);
}

template <class K, class V>
pair<K, V> binary_search_tree<K,V>::floor(K key) {
    tree_node<K,V> *ptr = root;
    tree_node<K,V> *ans = null;
    while(ptr != null) {
        if(ptr->key == key) {ans = ptr; break;}
        if(ptr->key > key) {ptr = ptr->left;}
        else if(ptr->key < key) {ans = ptr; ptr = ptr->right;}
    }
    return (ans == null) ? DUMMY_KV_PAIR : MP(ans->key, ans->data);
}

template <class K, class V>
vector<pair<K,V> > binary_search_tree<K,V>::getInRange(K left, K right) {
    vector<pair<K,V> >result;
    getInRange(root, left, right, result);
    return result;
}

template <class K, class V>
vector<pair<K,V> > binary_search_tree<K,V>::getInRange(tree_node<K,V> *node, K left, K right, vector<pair<K,V> > &result){
    if(node == null) return ;
    if(node->key > right) getInRange(node->left, left, right, result);
    else if(node->key < left) getInRange(node->right, left, right, result);
    else {
        getInRange(node->left, left, right, result);
        getInRange(node->right, left, right, result);
    }
}
