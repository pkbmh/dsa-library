//
// Created by Pankaj Birat on 28/11/18.
//

#ifndef DSA_LIST_ITERATOR_H
#define DSA_LIST_ITERATOR_H

#endif //DSA_LIST_ITERATOR_H

#include "list_node.cpp"

template <class T>
class list_iterator {
private:
    list_node<T> *current_node;
    list_node<T> *prev_node;

public:
    explicit list_iterator(const list_node<T> *curr) {
        this->current_node = curr;
        this->prev_node = curr->prev;
    }
    bool has_next(){
        return (current_node != null);
    }
    bool has_prev() {
        return (prev_node != null);
    }
    list_node<T> next() {
        if(has_next()) {
            list_node<T> tmp = *current_node;
            prev_node = current_node;
            current_node = current_node->next;
            return tmp;
        }
        return null;
    };
    list_node<T> prev() {
        if(has_prev()) {
            list_node<T> tmp = *prev_node;
            current_node = prev_node;
        }
        return null;
    };
};