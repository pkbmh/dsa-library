//
// Created by Pankaj Birat on 29/11/18.
//

#ifndef DSA_BINARY_SEARCH_TREE_H
#define DSA_BINARY_SEARCH_TREE_H

#include "binary_tree_traverser.cpp"

// TODO find(key), delete(key), range_search(key left, key right), ceil(key), floor(key)
template <class K, class V>
class binary_search_tree {

private:
    tree_node<K,V> * root;
    binary_tree_traverser<K,V> treeTraverser;
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
    pair<K, V> find(K key);
    pair<K, V> ceil(K key);
    pair<K, V> floor(K key);
    vector<pair<K,V> > getInRange(K left, K right);

    void printInOrder() {
        treeTraverser.printInOrder(root);
    }
    void printPreOrder() {
        treeTraverser.printPreOrder(root);
    }
    void printPostOrder() {
        treeTraverser.printPostOrder(root);
    }
    virtual ~binary_search_tree(){
    }
protected:
    tree_node<K,V> * leftMostNode(tree_node<K,V>*node);
    tree_node<K,V> * rightMostNode(tree_node<K,V>*node);
    vector<pair<K,V> > getInRange(tree_node<K,V> *node, K left, K right, vector<pair<K,V> > &result);
    virtual tree_node<K,V>* insert(tree_node<K,V> * node, K key, V value);
};


#endif //DSA_BINARY_SEARCH_TREE_H
