//
// Created by Pankaj Birat on 28/11/18.
//

#include "../../../datastructure/list/custom_list.cpp"


class custom_list_test {
public:
    void test() {
        custom_list<int> list;
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(5);
        list.insert(6);
        list.insert(7);

        list.print();

        assert(list.list_size() == 7);

        list_node<int>* head = list.getHead();
        assert(head != null);
        assert(head->prev == null);
        assert(head->next->data == 2);

        list_node<int>* tail = list.getTail();
        assert(tail != null);
        assert(tail->next == null);
        assert(tail->prev->data == 6);

        list_node<int> *listNode = list.find(5);
        assert(listNode != null);
        assert(listNode->prev->data == 4);
        assert(listNode->next->data == 6);

        list.deleteHead();
        assert(list.list_size() == 6);
        list_node<int>* newHead = list.getHead();
        assert(newHead != null);
        assert(newHead->prev == null);
        assert(newHead->next->data == 3);

        list.deleteTail();
        assert(list.list_size() == 5);
        list_node<int>* newTail = list.getTail();
        assert(newTail != null);
        assert(newTail->next == null);
        assert(newTail->prev->data == 5);


        list.deleteNode(listNode);
        assert(list.list_size() == 4);
        listNode = list.find(5);
        assert(listNode == null);

        list.print();

    }
};