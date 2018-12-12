//
// Created by Pankaj Birat on 12/12/18.
//

#ifndef DSA_BINARY_HEAP_H
#define DSA_BINARY_HEAP_H

#endif //DSA_BINARY_HEAP_H

#include "../../common/headers.hpp"


/**
 *
 * @tparam T Type of objects in the heap
 * this template requires the comparision function which should accept two parameters of type T and returns bool #true if first argument can be the parent of second, #false otherwise
 */
template <class T>
class binary_heap {
public:
    vector<T> arr;
    bool (*compFunction)(const T &, const T &);
    int maxSize;
    int currentSize;

    /**
     *
     * @param compFunction comparision function in this case max size will be INT_MAX
     * Initially heap is empty
     */
    binary_heap(bool (*compFunction)(const T &, const T &)) {
        this->currentSize = 0;
        this->maxSize = INT_MAX;
        this->compFunction = compFunction;
    }


    /**
     *
     * @param sz maximum size of heap
     * @param compFunction comparision function
     * Initially heap is empty
     */
    binary_heap(int sz, bool (*compFunction)(const T &, const T &)) {
        this->currentSize = 0;
        this->maxSize = sz;
        this->compFunction = compFunction;
        this->arr.clear();
        this->arr.resize(sz);
    }

    /**
     *
     * @param arr initial array to be transformed in heap
     * @param compFunction
     * Initially heap is build by arr in input
     */
    binary_heap(vector<T> &arr, bool (*compFunction)(const T &, const T &)) {
        copy(arr.begin(), arr.end(), std::back_inserter(this->arr));
        maxSize = arr.size();
        this->compFunction = compFunction;
        currentSize = maxSize;
        build();
    }

    void insert(T a);
    T getTop();
    void deleteTop();
    ~binary_heap(){
        arr.clear();
        arr.shrink_to_fit();
    }
private:
    // TODO code duplication use composition of helper class
    int left_ind(int ind) { return (ind<<1)+1;}
    int right_ind(int ind) { return (ind<<1)+2;}
    int parent_ind(int ind) { return (ind-1)>>1;}
    void build();
    void heapify(int ind);
};

template <class T>
void binary_heap<T>::build() {
    // Build heap (rearrange array)
    for (int i = currentSize / 2 - 1; i >= 0; i--)
        heapify(i);
}

template <class T>
void binary_heap<T>::heapify(int ind) {
    int left = left_ind(ind);
    int right = right_ind(ind);
    int next_ind = ind;
    if(left < currentSize && !compFunction(arr[next_ind], arr[left])) next_ind = left;
    if(right < currentSize && !compFunction(arr[next_ind], arr[right])) next_ind = right;
    if(next_ind != ind) {
        swap(arr[ind], arr[next_ind]);
        heapify(next_ind);
    }
}

template <class T>
T binary_heap<T>::getTop() {
    if(currentSize == 0)  {
        cout << "Heap is empty" << endl;
        return T{};
    }
    return arr[0];
}

template <class T>
void binary_heap<T>::deleteTop() {
    if(currentSize == 0)  {
        cout << "Heap is empty" << endl;
        return;
    }
    swap(arr[0], arr[currentSize-1]);
    --currentSize;
    heapify(0);
}

template <class T>
void binary_heap<T>::insert(T a) {
    if(currentSize == maxSize) {
        cout << "Overflow: Could not insertKey" << endl;
        return;
    }
    if(maxSize == INT_MAX && arr.size() <= currentSize) {
        // allocate new entry because we haven't reserved anything in the array to index access is not available
        arr.push_back(T{});
    }
    arr[currentSize++] = a;
    int ind = currentSize - 1;
    while(ind != 0 && !compFunction(arr[parent_ind(ind)], arr[ind])) {
        swap(arr[parent_ind(ind)], arr[ind]);
        ind = parent_ind(ind);
    }
}