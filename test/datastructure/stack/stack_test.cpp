//
// Created by Pankaj Birat on 29/11/18.
//

#include "../../../common/headers.hpp"

class stack_test {
public:
    void test() {
        stack<int> st;
        for(int i = 0; i < 5; i++) st.push(i);
        int a = st.top();
        assert(st.size() == 5);
        assert(!st.empty());
        assert(a == 4);
    }
};