/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache( 2 ); // 2 = capacity
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);    // returns 1
 * cache.put(3, 3); // evicts key 2
 * cache.get(2);    // returns -1 (not found)
 * cache.put(4, 4); // evicts key 1
 * cache.get(1);    // returns -1 (not found)
 * cache.get(3);    // returns 3
 * cache.get(4);    // returns 4
 */

#include <bits/stdc++.h>

using namespace std;

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct node {
    int k, v;

    node(int key, int value) : k(key), v(value) {}
};

class LRUCache {
    int cap_;
    unordered_map<int, list<node>::iterator> mp_;
    list<node> list_;

private:
    void update(list<node>::iterator &it) {
        list_.splice(list_.begin(), list_, it);
    }

public:
    LRUCache(int capacity) : cap_(capacity), mp_(), list_() {
    }

    int get(int key) {
        auto it = mp_.find(key);
        if (it == mp_.end()) {
            return -1;
        }

        update(it->second);
        return it->second->v;
    }

    void put(int key, int value) {
        auto found = mp_.find(key);
        if (found != mp_.end()) {
            found->second->v = value;
            update(found->second);
        } else if (list_.size() == cap_) {
            node rm = list_.back();
            list_.pop_back();
            mp_.erase(rm.k);

            list_.push_front(node(key, value));
            mp_[key] = list_.begin();

            assert(list_.size() == cap_);
            assert(list_.size() == mp_.size());
        } else {
            list_.push_front(node(key, value));
            mp_[key] = list_.begin();
        }
    }
};

int main() {
    {
        LRUCache cache(2);

        cache.put(1, 1);
        cache.put(2, 2);
        assert(cache.get(1) == 1);  // returns 1
        cache.put(3, 3);            // evicts key 2
        assert(cache.get(2) == -1); // returns -1 (not found)
        cache.put(4, 4);            // evicts key 1
        assert(cache.get(1) == -1); // returns -1 (not found)
        assert(cache.get(3) == 3);  // returns 3
        assert(cache.get(4) == 4);  // returns 4
    }

    {
        LRUCache cache(1);
        cache.put(2, 1);
        assert(cache.get(2) == 1);
    }

    return 0;
}
