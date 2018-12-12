//
// Created by Pankaj Birat on 12/12/18.
//
#include "../../../datastructure/range-query/binary_index_tree.hpp"

class binary_index_tree_test {
public:
    void test() {
        srand(time(NULL));
        int sz = rand() % 100000 + 100;
        vector<int> vec;
        vec.reserve(sz);
        for(int i = 0; i < sz; i++) vec.push_back((rand()%10000000));
        binary_index_tree<int> binaryIndexTree(vec);
        cout << "Starting Random 1000 test cases mix of update and query" << endl;
        for(int i = 0; i < 1000; i++){
            int left = rand() % sz;
            int right = rand() % sz;
            if(left > right) swap(left, right);
            int bl = rand() % 2;
            if(bl) {
                int res =  binaryIndexTree.query(left, right);
                int sum = accumulate(vec.begin() + left, vec.begin()+right+1, 0);
                assert(sum == res);
            }else {
                int tmp = right + rand() % 10000000;
                vec[left] += tmp;
                binaryIndexTree.update(left, tmp);
            }
        }
        cout << "All test case successfully passed" << endl;
    }
};