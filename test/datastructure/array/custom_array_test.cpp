//
// Created by Pankaj Birat on 28/11/18.
//
#include "../../../datastructure/array/custom_array.h"

class custom_array_test {
public:
    void test() {
        custom_array<int> customArray(10);
        for (int i = 0; i < 10; i++) {
            customArray.setAt(i, i);
        }
        customArray[0] = 100;
        assert(customArray[0] == 100);
        customArray.print();
        try {
            customArray.getAt(100);
        } catch (runtime_error error) {
            cout << error.what() << endl;
        }
    }
};