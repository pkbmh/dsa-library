//
// Created by Pankaj Birat on 28/11/18.
//


#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct node {
    int a;
    int b;
};

class container_test {
public:

    static bool foo(const node &a) {
        return a.a == a.b;
    }
    void run() {
        cout << "Hello, World!" << std::endl;
        int arr[] = {1,3,4,4,6,7,8,8,8,9,9,9,9};
        int sz = sizeof(arr) / sizeof(int);
        int ind = lower_bound(arr, arr+sz, 9) - arr;
        int indu = upper_bound(arr, arr+sz, 9) -arr;

        int ind_n = search_n(arr, arr+sz, 2, 4) - arr;

//    int nth = nth_element(arr, arr+sz) - arr;
        cout << ind << " " << indu << " " << ind_n << endl;


        int arr1[] = {1,3,5,7,9};
        int sz1 = sizeof(arr1) / sizeof(int);
        bool res = all_of(arr1, arr1+sz1, [](int a){ return a%2;});
        cout << "res : " << res << endl;

        node n_arr[] = {{0,0}, {1,1}, {2,2}};
        bool res1 = all_of(n_arr, n_arr+3, foo);
        cout << "res1 : " << res1 << endl;
        transform(n_arr, n_arr+3, n_arr, [](const node &a){ node x = {a.a*2, a.b*2}; return x;});
        for(node i : n_arr) cout << i.a << " "<< i.b << " : "; cout << endl;

        int rot_arr[] = {1,2,3,4,5,6,7,8};
        reverse(rot_arr, rot_arr+5);
        for (int i : rot_arr) cout << i << " "; cout << endl;

        transform(arr, arr+sz, arr, [](int a){ return a*2;});
        for(int i : arr) cout << i << " "; cout << endl;
        vector<int>
        set<int>::iterator;
        set<int>m{1,4,5,6,3,7};
        set<int>n{1,3,5};
        set<int>i_mn;
        set_intersection(m.begin(), m.end(), n.begin(), n.end(), inserter(i_mn,i_mn.begin()));
        for(int i:i_mn) cout << i << " "; cout << endl;
    }
};


