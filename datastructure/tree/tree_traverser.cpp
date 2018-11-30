//
// Created by Pankaj Birat on 29/11/18.
//

#include "tree_node.hpp"

template <class K, class V>
class tree_traverser {
public:
    void printInOrder(tree_node<K,V>*root);
    void printPreOrder(tree_node<K,V>*root);
    void printPostOrder(tree_node<K,V>*root);
};


template <class K, class V>
void tree_traverser<K,V>::printInOrder(tree_node<K,V>*root) {
    if(root == null) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

template <class K, class V>
void tree_traverser<K,V>::printPreOrder(tree_node<K,V>*root) {
    if(root == null) return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

template <class K, class V>
void tree_traverser<K,V>::printPostOrder(tree_node<K,V>*root) {
    if(root == null) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}