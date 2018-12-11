//
// Created by Pankaj Birat on 11/12/18.
//

#ifndef DSA_SPARSE_TABLE_H
#define DSA_SPARSE_TABLE_H

#endif //DSA_SPARSE_TABLE_H
#pragma once

/*
 * Sparse table is a kind of table/data structure which can be used for answering the range based query like minimum in range/maximum in range etc.
 * Update are not allowed run time
 * space complexity is O(nlogn)
 * time complexity of query is O(1)
 * preprocessing time is O(nlogn)
 */

#include "../../common/headers.hpp"

/**
 *
 * @tparam T data type of underlying container
 * @tparam Comp comparision function which should compare two objects of type T and return 1 if need to keep first argument 0 otherwise
 */
template <class T>
class sparse_table {
private:
    vector<T> arr;
    int **table;
    size_t sz;
    int (*compareFunction)(T, T);

public:

    sparse_table(vector<T> arr, int (*compareFunction)(T, T)) {
        this->arr = arr;
        sz = arr.size();
        this->compareFunction = compareFunction;
        build();
    }
    T query(int left, int right);
    ~sparse_table(){
        for(int i = 0; i < arr.size(); i++){
            free(table[i]);
        }
        arr.clear();
        arr.shrink_to_fit();
    }
private:
    void build();
};

template <class T>
void sparse_table<T>::build() {
    table = (int **)malloc(sz * sizeof(int *));
    int lg2 = log2(sz) + 1;
    for(int i = 0; i < sz; i++) {
        table[i] = (int *)malloc(lg2 * sizeof(int));
    }
    // for length 1 so ans of len 1 starting form i would be i;

    for(int i = 0; i < sz; i++) table[i][0] = i;
    for(int j = 1; j < lg2; j++) {
        int len = (1<<j);
        int len_b2 = (len >> 1);
        for(int i = 0; i+len <= sz; i++) {
            int comp_res = compareFunction(arr[table[i][j-1]], arr[table[i+len_b2][j-1]]);
            table[i][j] = ((comp_res == 1) ? table[i][j-1] : table[i+len_b2][j-1]);
        }
    }

    for(int j = 0; j < lg2; j++) {
        for(int i = 0; i+(1<<j) <= sz; i++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

template <class T>
T sparse_table<T>::query(int left, int right) {
    assert(left <= right);
    assert(right < sz);
    int len = right - left + 1;
    int j = log2(len);
    return compareFunction(arr[table[left][j]], arr[table[left+len-(1<<j)][j]]) ? arr[table[left][j]] : arr[table[left+len-(1<<j)][j]];
}