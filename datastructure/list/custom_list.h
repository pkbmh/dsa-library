//
// Created by Pankaj Birat on 28/11/18.
//

#ifndef DSA_LIST_H
#define DSA_LIST_H

#endif //DSA_LIST_H

#include "../../common/headers.h"
#include "../../common/common_functions.h"
#include "../../common/list_exceptions.h"
#include "list_iterator.cpp"
#include "../printable.h"

template <class T>
class custom_list : public printable<T>{
private:
    list_node<T> *head;
    list_node<T> *tail;
    int size;

public:
    custom_list<T>(){
        cout << "creating custom list" << endl;
        head = null;
        tail = null;
    }
    list_node<T> * getHead();
    list_node<T> * getTail();
    list_node<T> *find(T data);
    void insert(T data);
    bool deleteHead();
    bool deleteTail();
    bool deleteNode(list_node<T> *node);
    int list_size();

    void print() {
        list_node<T> *tmp = head;
        while(tmp != null) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

