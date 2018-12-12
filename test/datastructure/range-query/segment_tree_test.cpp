//
// Created by Pankaj Birat on 11/12/18.
//
#include "../../../datastructure/range-query/segment_tree.hpp"

class segment_tree_test {
public:
    void test(){
        srand(time(NULL));
        int sz = rand() % 100000 + 100;
        vector<int> vec;
        vec.reserve(sz);
        for(int i = 0; i < sz; i++) vec.push_back((rand()%10000000));

        segment_tree<int, segment_tree_nodes::min_max_int_node> segmentTree(vec,  segment_tree_nodes::min_max_int_node::makeFunction, segment_tree_nodes::min_max_int_node::mergeFunction);

        cout << "Starting Random 1000 test cases mix of update and query" << endl;
        srand(time(NULL));

        for(int i = 0; i < 1000; i++) {
            int left = rand() % sz;
            int right = rand() % sz;
            if(left > right) swap(left, right);
            int bl = rand() % 2;
            if(bl) {
                segment_tree_nodes::min_max_int_node res =  segmentTree.query(left, right);
                int mn = *min_element(vec.begin() + left, vec.begin()+right+1);
                int mx = *max_element(vec.begin() + left, vec.begin()+right+1);
                assert(mn == res.mn);
                assert(mx == res.mx);
            }else {
                vec[left] = right + rand() % 100;
                segmentTree.update(left, vec[left]);
            }
        }
    }
};