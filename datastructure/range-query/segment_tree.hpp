//
// Created by Pankaj Birat on 11/12/18.
//

#ifndef DSA_SEGMENT_TREE_H
#define DSA_SEGMENT_TREE_H

#endif //DSA_SEGMENT_TREE_H

#include "../../common/headers.hpp"

/**
 *
 * @tparam T type of underlying container
 * @tparam TreeNode type of segment tree node
 */

/**
 *
 * @param vector<T>
 * @Param makeFunction a function which will be used to create leaf node of tree, give a value of type T this function should return leaf node for this value
 * @Param mergeFunction a fucntion which will merge two segment tree node
 */
template <class T, class TreeNode>
class segment_tree {
private:
    vector<T> arr;
    size_t sz;
    TreeNode *tree;
    TreeNode (*mergeFunction)(TreeNode, TreeNode);
    TreeNode (*makeFunction)(T);
public:
    segment_tree(vector<T> arr, TreeNode (*makeFunction)(T), TreeNode (*mergeFunction)(TreeNode, TreeNode)) {
        this->arr = arr;
        this->sz = arr.size();
        this->mergeFunction = mergeFunction;
        this->makeFunction = makeFunction;
        // TODO Fix the proper size
        this->tree = (TreeNode *)malloc(4 * sz * sizeof(TreeNode));
//        this->tree = new TreeNode*[sz];
        build(0, 0, sz-1);
    }
    TreeNode query(int left, int right) {
        assert(left <= right);
        assert(right < sz);
        return query(0, 0, sz-1, left, right);
    }
    void update(int ind, T val) {
        update(0, 0, sz-1, ind, val);
    }

    ~segment_tree(){
        cout << "destroying segment tree" << endl;
        free(tree);
    }
private:
    void build(int ind, int left, int right);
    TreeNode query(int ind, int left, int right, int p, int q);
    void update(int ind, int left, int right, int index, T val);
    // inline utility functions
    int get_mid(int left, int right){return (left+right)>>1;}
    int left_ind(int ind) { return (ind<<1)+1;}
    int right_ind(int ind) { return (ind<<1)+2;}
    int parent_ind(int ind) { return (ind-1)>>1;}
};

template <class T, class TreeNode>
void segment_tree<T, TreeNode>::build(int ind, int left, int right) {
    if(left == right) {
        tree[ind] = makeFunction(arr[left]);
        return;
    }

    int mid = get_mid(left, right);
    build(left_ind(ind), left, mid);
    build(right_ind(ind), mid+1, right);
    tree[ind] = mergeFunction(tree[left_ind(ind)], tree[right_ind(ind)]);
}

template <class T, class TreeNode>
TreeNode segment_tree<T, TreeNode>::query(int ind, int left, int right, int p, int q) {
    if(left >= p && right <= q) return tree[ind];
    int mid = get_mid(left, right);
    if(q <= mid) return query(left_ind(ind), left, mid, p, q);
    if(p > mid) return query(right_ind(ind), mid+1, right, p, q);
    return mergeFunction( query(left_ind(ind), left, mid, p, q), query(right_ind(ind), mid+1, right, p, q));
}


template <class T, class TreeNode>
void segment_tree<T, TreeNode>::update(int ind, int left, int right, int index, T val) {
    if(left == right) {
        tree[ind] = makeFunction(val);
        return;
    }
    int mid = get_mid(left, right);
    if(mid >= index) update(left_ind(ind), left, mid, index, val);
    else update(right_ind(ind), mid+1, right, index, val);
    tree[ind] = mergeFunction(tree[left_ind(ind)], tree[right_ind(ind)]);
}

// Example node and functions for creating and testing segment tree
namespace segment_tree_nodes {
        struct min_max_int_node {
            int mn;
            int mx;

            static min_max_int_node makeFunction(int a) {

                min_max_int_node *tmp = (min_max_int_node *) malloc(sizeof(min_max_int_node));
                tmp->mn = a;
                tmp->mx = a;

                return *tmp;
            }

            static min_max_int_node mergeFunction(min_max_int_node first, min_max_int_node second) {

                min_max_int_node *tmp = new min_max_int_node;
                tmp->mn = min(first.mn, second.mn);
                tmp->mx = max(first.mx, second.mx);

                return *tmp;
            }
        };
    }