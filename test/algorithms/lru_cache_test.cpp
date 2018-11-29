//
// Created by Pankaj Birat on 29/11/18.
//
#include "../../algorithms/lru_cache.cpp"

class lru_cache_test {
public:
    void test() {
        lru_cache<int, string> lruCache(4);
        lruCache.put(1, "one");
        lruCache.put(2, "two");
        lruCache.put(3, "three");
        lruCache.put(4, "four");
        //  1 , 2 , 3, 4
        lruCache.print();

        lruCache.put(5, "five");
        lruCache.get(2);

        // 3 4 5 2
        lruCache.print();

        // 4 5 2 6
        lruCache.put(6, "six");

        // 5 2 6 4
        lruCache.put(4, "four");

        // 2 6 4 7
        lruCache.put(7, "seven");
        lruCache.print();


    }
};
