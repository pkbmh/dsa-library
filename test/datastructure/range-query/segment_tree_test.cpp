//
// Created by Pankaj Birat on 11/12/18.
//
#include "../../../datastructure/range-query/segment_tree.hpp"

class segment_tree_test {
public:
    void test(){
        int arr[] = {2,3,1,4,5,1,6,7,8,1,7,1,4,5,6,7};
        int sz = sizeof(arr) / sizeof(int);
        vector<int> vec(arr, arr+sz);

        segment_tree<int, segment_tree_nodes::min_max_int_node> segmentTree(vec,  segment_tree_nodes::min_max_int_node::makeFunction, segment_tree_nodes::min_max_int_node::mergeFunction);

        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,3).mn == 1);

        cout << "segmentTree.query(0,3).mx " << segmentTree.query(0,3).mx << endl;
        assert(segmentTree.query(0,3).mx == 4);

        cout << "segmentTree.query(0,4).mn " << segmentTree.query(0,4).mn << endl;
        assert(segmentTree.query(0,4).mn == 1);

        cout << "segmentTree.query(0,4).mx " << segmentTree.query(0,4).mx << endl;
        assert(segmentTree.query(0,4).mx == 5);

        cout << "segmentTree.query(0,0).mx " << segmentTree.query(0,0).mx << endl;
        assert(segmentTree.query(0,0).mx == 2);

        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,0).mn == 2);

        cout << "segmentTree.query(2,4).mn " << segmentTree.query(2,4).mn << endl;
        assert(segmentTree.query(2,4).mn == 1);

        cout << "segmentTree.query(2,4).mx " << segmentTree.query(2,4).mx << endl;
        assert(segmentTree.query(2,4).mx == 5);

        cout << "segmentTree.query(sz-1,sz-1).mn " << segmentTree.query(sz-1,sz-1).mn << endl;
        assert(segmentTree.query(sz-1,sz-1).mn == 7);

        cout << "segmentTree.query(sz-2,sz-1).mn " << segmentTree.query(sz-2,sz-1).mn << endl;
        assert(segmentTree.query(sz-2,sz-1).mn == 6);

        cout << "segmentTree.query(sz-2,sz-1) " << segmentTree.query(sz-2,sz-1).mx << endl;
        assert(segmentTree.query(sz-2,sz-1).mx == 7);

        segmentTree.update(0, 0);
        vec[0] = 0;
        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,3).mn == 0);

        cout << "segmentTree.query(0,3).mx " << segmentTree.query(0,3).mx << endl;
        assert(segmentTree.query(0,3).mx == 4);

        cout << "segmentTree.query(0,4).mn " << segmentTree.query(0,4).mn << endl;
        assert(segmentTree.query(0,4).mn == 0);

        cout << "segmentTree.query(0,4).mx " << segmentTree.query(0,4).mx << endl;
        assert(segmentTree.query(0,4).mx == 5);

        cout << "segmentTree.query(0,0).mx " << segmentTree.query(0,0).mx << endl;
        assert(segmentTree.query(0,0).mx == 0);

        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,0).mn == 0);


        segmentTree.update(2, 100);
        vec[2] = 100;
        segmentTree.update(0, 2);
        vec[0] = 2;
        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,3).mn == 2);

        cout << "segmentTree.query(0,3).mx " << segmentTree.query(0,3).mx << endl;
        assert(segmentTree.query(0,3).mx == 100);

        cout << "segmentTree.query(0,4).mn " << segmentTree.query(0,4).mn << endl;
        assert(segmentTree.query(0,4).mn == 2);

        cout << "segmentTree.query(0,4).mx " << segmentTree.query(0,4).mx << endl;
        assert(segmentTree.query(0,4).mx == 100);

        cout << "segmentTree.query(0,0).mx " << segmentTree.query(0,0).mx << endl;
        assert(segmentTree.query(0,0).mx == 2);

        cout << "segmentTree.query(0,3).mn " << segmentTree.query(0,3).mn << endl;
        assert(segmentTree.query(0,0).mn == 2);

        random_verifier(vec, segmentTree);
    }

private:
//    template <class T, class TreeNode>
    void random_verifier(vector<int> vec, segment_tree<int, segment_tree_nodes::min_max_int_node> &segmentTree) {
        cout << "starting random verifier" << endl;
        int sz = vec.size();
        srand(time(NULL));

        for(int i = 0; i < 100; i++) {
            int left = rand() % sz;
            int right = rand() % sz;
            if(left > right) swap(left, right);

            int bl = rand() % 2;
            if(bl) {
                segment_tree_nodes::min_max_int_node res =  segmentTree.query(left, right);
                int mn = *min_element(vec.begin() + left, vec.begin()+right+1);
                int mx = *max_element(vec.begin() + left, vec.begin()+right+1);

//                if(mn != res.mn || mx != res.mx) {
//                    cout << "actual " << mn << " " << mx << endl;
//                    cout << "query (" << left << "," << right << ")" << "min= " << res.mn << " max = " << res.mx << " "
//                         << endl;
                assert(mn == res.mn);
                assert(mx == res.mx);
//                }

            }else {
                vec[left] = right + rand() % 100;
                segmentTree.update(left, vec[left]);
            }
        }
    }
};