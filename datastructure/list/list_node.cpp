//
// Created by Pankaj Birat on 28/11/18.
//
#include "../../common/headers.hpp"

template <class T>
struct list_node {
    T data;
    list_node<T> *next;
    list_node<T> *prev;

    static list_node<T> *new_node(const T data) {
        auto *tmp = new list_node;
        tmp->data = data;
        tmp->next = null;
        tmp->prev = null;
        return tmp;
    }
};