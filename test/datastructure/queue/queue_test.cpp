//
// Created by Pankaj Birat on 29/11/18.
//

#include "../../../common/headers.hpp"

class queue_test {
public:
    void test() {
        queue<int> qu;
        for(int i = 0; i < 5; i++) qu.push(i);
        int a = qu.front();
        assert(qu.size() == 5);
        assert(!qu.empty());
        assert(a == 0);
    }
};