//
// Created by Pankaj Birat on 30/11/18.
//

#include "../../../datastructure/tree/avl_tree.cpp"
#include "../../../common/common_functions.h"

class avl_tree_test {
public:
    void test() {
        binary_search_tree<long, int> *avlTree = new avl_tree<long,int>();
        long mx = 0;
        long mn = LONG_MAX;

        for(int i = 0; i < 20; i++) {
            avlTree->insert(i, i);
        }
        mx = 19;
        mn = 0;
        cout << avlTree->getMax() << endl;
        cout << avlTree->getMin() << endl;
        assert(mx == avlTree->getMax().F);
        assert(mn == avlTree->getMin().F);

        avlTree->printInOrder();

    }
};