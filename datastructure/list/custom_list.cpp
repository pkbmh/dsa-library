//
// Created by Pankaj Birat on 28/11/18.
//
#include "custom_list.h"

template <class T>
list_node<T>* custom_list<T>::getHead() {
    return head;
}

template <class T>
list_node<T>* custom_list<T>::getTail() {
    return tail;
}

template <class T>
list_node<T>* custom_list<T>::find(T data) {
    if(head == null) return null;
    list_node<T>*front = head;
    list_node<T>*back = tail;
    while (front != back) {
        if(front->data == data) return front;
        if(back->data == data) return back;
        front = front->next;
        if(front == back) break;
        back = back->prev;
    }
    if(front->data == data) return front;
    return null;
}
template <class T>
void custom_list<T>::insert(T data) {
    list_node<T> *tmp = list_node<T>::new_node(data);
    if(head == null) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
    size++;
}

template <class T>
bool custom_list<T>::deleteHead() {
    if(head == null) return false;
    if(head == tail) {
       free(head);
       head = null;
       tail = null;
    }else {
        list_node<T> *tmp = head;
        head = head->next;
        head->prev = null;
        free(tmp);
    }
    size--;
    return true;
}

template <class T>
bool custom_list<T>::deleteTail() {
    if(tail == null) return false;
    if(tail == head) {
        free(tail);
        head = null;
        tail = null;
    } else {
        list_node<T> *tmp = tail;
        tail = tail->prev;
        tail->next = null;
        free(tmp);
    }
    size--;
    return true;
}

template <class T>
bool custom_list<T>::deleteNode(list_node<T> *node) {
    if(node == null) return false;
    if(node->prev == null) {
        // head delete
        return deleteHead();
    }else if(node->next == null) {
        // tail delete
        return deleteTail();
    }else {
        list_node<T> *prev = node->prev;
        list_node<T> *next = node->next;
        prev->next = next;
        next->prev = prev;
        free(node);
    }
    size--;
    return true;
}

template <class T>
int custom_list<T>::list_size() {
    return size;
}