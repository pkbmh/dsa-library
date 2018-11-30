//
// Created by Pankaj Birat on 29/11/18.
//

#ifndef DSA_BINARY_SEARCH_TREE_H
#define DSA_BINARY_SEARCH_TREE_H

#include "tree_traverser.cpp"

template <class K, class V>
class binary_search_tree {

private:
    tree_node<K,V> * root;
    tree_traverser<K,V> treeTraverser;
    pair<K,V> DUMMY_KV_PAIR;
public:
    binary_search_tree(){
        this->root = null;
    }
    int getHeight();
    int getSize();
    void insert(K key, V value);
    pair<K, V> getMax();
    pair<K, V> getMin();
    void printInOrder() {
        treeTraverser.printInOrder(root);
    }
    void printPreOrder() {
        treeTraverser.printPreOrder(root);
    }
    void printPostOrder() {
        treeTraverser.printPostOrder(root);
    }

protected:
    tree_node<K,V> * leftMostNode(tree_node<K,V>*node);
    tree_node<K,V> * rightMostNode(tree_node<K,V>*node);
    virtual tree_node<K,V>* insert(tree_node<K,V> * node, K key, V value);
};


#endif //DSA_BINARY_SEARCH_TREE_H
