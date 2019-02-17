int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n= nums.size();
        int mx_reach = nums[0];
        int n_mx_reach = -1;
        int step = 1;
        int i = 1;
        while(i < n) {
            if(mx_reach >= n-1) return step;
            
            if(i > mx_reach) {
                if(n_mx_reach == -1) return -1;
                mx_reach = n_mx_reach;
                n_mx_reach = -1;
                step++;
            }
            
            else {
                n_mx_reach = max(n_mx_reach, i+nums[i]);
                i++;
            }
        }
        
        return step;
    }//
// Created by Pankaj Birat on 29/11/18.
//

#include "../datastructure/list/custom_list.cpp"

template <class K, class V>
class lru_cache {
private:
    custom_list<pair<K,V> > list;
    map<K, list_node<pair<K,V> > * > list_node_map;
    int capacity;
public:
    explicit lru_cache(const int capacity) {
        this->capacity = capacity;
    }
    V get(K key);
    void put(K key, V value);
    void print(){
        list.print();
    }
};

template <class K, class V>
V lru_cache<K,V>::get(K key) {
    auto entry = list_node_map.find(key);
    if(entry == list_node_map.end()) return null;
    put(key, entry->S->data.S);
    return entry->S->data.S;
}

template <class K, class V>
void lru_cache<K, V>::put(K key, V val) {
    pair<K,V> value = {key, val};
    if(list_node_map.find(key) != list_node_map.end()) {
        list.deleteNode(list_node_map[key]);
        list.insert(value);
    }else {
        if(list.list_size() == capacity) {
            K key = list.getHead()->data.F;
            list.deleteHead();
            list.insert(value);
            list_node_map.erase(list_node_map.find(key));
        }else {
            list.insert(value);
        }
    }
    list_node_map.insert({key, list.getTail()});
}

