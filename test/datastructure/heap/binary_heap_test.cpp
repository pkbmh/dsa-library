//
// Created by Pankaj Birat on 12/12/18.
//

#include "../../../datastructure/heap/binary_heap.hpp"

class binary_heap_test {
public:
    void test() {
        srand(time(NULL));

        cout << "Testing infinite and bounded heap" << endl;
        set<int>boundedHeapElements;
        vector<int>arr;
        for(int i = 0; i < 1000; i++) boundedHeapElements.insert(rand());
        arr.assign(boundedHeapElements.begin(), boundedHeapElements.end());
        int boundedSize = 1000;
        binary_heap<int> binaryMaxBoundedHeap(arr, compMaxHeap);


        binary_heap<int> binaryMaxHeap(compMaxHeap);
        binary_heap<int> binaryMinHeap(compMinHeap);
        set<int> minSet, maxSet;
        minSet.insert(rand());
        maxSet.insert(rand());
        binaryMaxHeap.insert(*maxSet.begin());
        binaryMinHeap.insert(*minSet.begin());
        int getTopOps = 0, insertOps = 0, deleteOps = 0;

        for(int i = 0; i < 1000; i++) {
            int op = rand() % 3;
            if(op == 0) {
                ++getTopOps;
                int expectedMax = *maxSet.rbegin();
                int actualMax = binaryMaxHeap.getTop();
                assert(expectedMax == actualMax);

                int expectedMin = *minSet.begin();
                int actualMin = binaryMinHeap.getTop();
                assert(expectedMin == actualMin);

                int boundedExpected = binaryMaxBoundedHeap.getTop();
                int boundedActual = *boundedHeapElements.rbegin();
                assert(boundedExpected == boundedActual);

            }else if(op == 1){
                ++insertOps;
                int tmp = rand();
                maxSet.insert(tmp);
                minSet.insert(tmp);
                binaryMaxHeap.insert(tmp);
                binaryMinHeap.insert(tmp);

                if(boundedHeapElements.size() < boundedSize) boundedHeapElements.insert(tmp);
                // tried insert to test this insert should not apply
                binaryMaxBoundedHeap.insert(tmp);
            }else {
                if(maxSet.size() > 1 && minSet.size() > 1) {
                    ++deleteOps;
                    binaryMaxHeap.deleteTop();
                    set<int>::iterator it = maxSet.end(), it1 = boundedHeapElements.end();
                    it--;
                    maxSet.erase(it);

                    binaryMinHeap.deleteTop();
                    minSet.erase(minSet.begin());

                    it1--;
                    binaryMaxBoundedHeap.deleteTop();
                    boundedHeapElements.erase(it1);
                }
            }
        }
        cout << "All test passed for infinite and bounded heap" << endl;
        cout << "Testing operations Insert operation = " << insertOps << ",  GetTop Operation = "<< getTopOps << ", DeleteOps = "<< deleteOps << endl;
    }
    static bool compMaxHeap(const int &a, const int &b) {
        return (a >= b);
    }

    static bool compMinHeap(const int &a, const int &b) {
        return (a <= b);
    }
};