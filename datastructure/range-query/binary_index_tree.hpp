//
// Created by Pankaj Birat on 12/12/18.
//

#ifndef DSA_BINARY_INDEX_TREE_H
#define DSA_BINARY_INDEX_TREE_H

#endif //DSA_BINARY_INDEX_TREE_H

#include "../../common/headers.hpp"

/*
 * T should support the - and + operator to work on because it relies on the fact that the accumulative result from a to b is f(b)-f(a-1)
 * T also should handle default initialization
 */
template <class T> class binary_index_tree {
private:
private:
    vector<T> tree;
    size_t sz;

public:
    binary_index_tree(vector<T> arr) {
        this->sz = arr.size();
        this->tree.clear();
        this->tree.resize(sz+1);
        build(arr);
    }
    void update(int ind, T newValue);
    T query(int left, int right);

    ~binary_index_tree(){
        cout << "destroying BIT" << endl;
        tree.clear();
        tree.shrink_to_fit();
    }
    void print(){
        for(int i = 1; i <= sz; i++) cout << tree[i] << " "; cout << endl;
    }
private:
    void build(vector<T> &arr);
    // from 0 to ind
    T query(int ind);
};

template <class T>
void binary_index_tree<T>::build(vector<T> &arr) {
    for(int i = 0; i <= sz; i++) tree[i] = T{};
    for(int i = 0; i < sz; i++) {
        update(i, arr[i]);
    }
}

template <class T>
void binary_index_tree<T>::update(int ind, T newValue) {
    ind++;
    while(ind <= sz) {
        tree[ind] += newValue;
        ind += ind & (-ind);
    }
}

template <class T>
T binary_index_tree<T>::query(int left, int right) {
    right++;
    return query(right) - query(left);
}

template <class T>
T binary_index_tree<T>::query(int ind) {
    T result{};
    while(ind > 0) {
         result += tree[ind];
        ind -= ind & (-ind);
    }
    return result;
}