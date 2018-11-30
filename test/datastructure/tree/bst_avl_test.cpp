//
// Created by Pankaj Birat on 30/11/18.
//

#include "../../../datastructure/tree/bst_avl.cpp"
#include "../../../common/common_functions.h"

class bst_avl_test {
public:
    void test() {
        binary_search_tree<long, int> *avlTree = new bst_avl<long,int>();
        long mx = 0;
        long mn = LONG_MAX;

        for(int i = 0; i < 20; i++) {
            avlTree->insert(i, i);
        }
        mx = 19;
        mn = 0;

        cout << "max : " <<  avlTree->getMax() << endl;
        cout << "min : " << avlTree->getMin() << endl;
        assert(mx == avlTree->getMax().F);
        assert(mn == avlTree->getMin().F);

        cout << "Inorder traversal" << endl;
        avlTree->printInOrder();

    }
};