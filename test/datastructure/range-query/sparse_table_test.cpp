//
// Created by Pankaj Birat on 11/12/18.
//

#include "../../../datastructure/range-query/sparse_table.hpp"
#pragma once

class sparse_table_test {
public:
    void test() {
        int arr[] = {5,6,1,3,7,2,5,7,1};
        int sz = sizeof(arr) / sizeof(int);
        vector<int> vec(arr, arr+sz);
        for(int i : vec) cout << i << " "; cout << endl;
        sparse_table<int> sparseTable(vec, sparse_table_test::comp);

        assert(sparseTable.query(0, sz-1) == 1);
        assert(sparseTable.query(0, 1) == 5);
        assert(sparseTable.query(1, 2) == 1);
        assert(sparseTable.query(2, 4) == 1);
        assert(sparseTable.query(0, 2) == 1);
        assert(sparseTable.query(3, sz-1) == 1);
        assert(sparseTable.query(3, sz-2) ==2);
        assert(sparseTable.query(sz-2, sz-1) == 1);
        assert(sparseTable.query(3, 4) == 3);
        assert(sparseTable.query(4, 4) == 7);
        assert(sparseTable.query(sz-1, sz-1) == 1);
        assert(sparseTable.query(sz-2, sz-2) == 7);
        assert(sparseTable.query(1, 1) == 6);
    }
    static int comp(int a, int b) {
        return a < b ? a : b;
    }
};