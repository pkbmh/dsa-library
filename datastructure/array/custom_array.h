//
// Created by Pankaj Birat on 28/11/18.
//


#include "../../common/headers.h"
#include "../../common/array_exceptions.h"

template<class T>
class custom_array{
    VI arr;
    int sz;
public:
    explicit custom_array(int size){
        arr.resize(size);
        this->sz = size;
    }

    void check_index_overflow(const int &ind) {
        if(ind >= sz) throw array_index_out_of_bound("Referred index is more then array size");
    }

    void check_index_negative(const int &ind) {
        if(ind < 0) throw negative_index_exception("Index can not be negative");
    }

    void index_check(const int &ind){
        check_index_overflow(ind);
        check_index_negative(ind);
    }

    T getAt(const int &ind) {
        index_check(ind);
        return arr[ind];
    }

    T &operator[](const int &ind) {
        index_check(ind);
        return arr[ind];
    }

    void setAt(const int ind, T v) {
        index_check(ind);
        arr[ind] = v;
    }

    void print(){
        for(T t : arr) cout << t << " ";
        cout << endl;
    }

    void print_ln() {
        for(T t : arr) cout << t << endl;
    }

    void reverse(int start_ind, int end_ind) {
        index_check(start_ind);
        index_check(end_ind);
        assert(start_ind <= end_ind);
        reverse(arr.begin()+start_ind, arr.begin()+end_ind);
    }
    ~custom_array(){
        cout << "destroying objects" << endl;
        arr.clear();
        arr.shrink_to_fit();
    }
};
