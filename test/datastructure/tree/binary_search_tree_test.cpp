//
// Created by Pankaj Birat on 29/11/18.
//
#include "../../../datastructure/tree/binary_search_tree.cpp"
#include "../../../common/common_functions.h"

class binary_search_tree_test {
public:
    void test() {
        binary_search_tree<long, string> binarySearchTree;
        long mx = 0;
        long mn = LONG_MAX;

        for(int i = 0; i < 20; i++) {
            long tmp = random();
            mx = max(mx, tmp);
            mn = min(mn, tmp);
            binarySearchTree.insert(tmp, to_string(i));
        }
        assert(mx == binarySearchTree.getMax().F);
        assert(mn == binarySearchTree.getMin().F);
        cout << "max : " << binarySearchTree.getMax() << endl;
        cout << "min : " << binarySearchTree.getMin() << endl;

        cout << "Inorder traversal" << endl;
        binarySearchTree.printInOrder();
    }
};