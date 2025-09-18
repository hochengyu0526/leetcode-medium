#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
private:
    // list stores key-value pairs
    list<pair<int, int>> cache;
    // map stores key and an iterator to its position in the list
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        
        // Move the accessed element to the front
        auto it = m[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        m[key] = cache.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            // Update an existing key: erase the old entry
            cache.erase(m[key]);
        } else if (cache.size() >= capacity) {
            // Evict the least recently used item
            int oldkey = cache.back().first;
            cache.pop_back();
            m.erase(oldkey);
        }
        
        // Insert the new/updated entry at the front
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};

int main() {
    cout << "Testing LRUCache with capacity 2" << endl;
    LRUCache lRUCache(2);

    // Test case 1
    cout << "put(1, 1)" << endl;
    lRUCache.put(1, 1); // cache is {1,1}
    cout << "put(2, 2)" << endl;
    lRUCache.put(2, 2); // cache is {2,2}, {1,1}

    cout << "get(1): " << lRUCache.get(1) << endl; // returns 1
    // cache is {1,1}, {2,2}

    cout << "put(3, 3)" << endl;
    lRUCache.put(3, 3); // LRU key 2 is removed, cache is {3,3}, {1,1}

    cout << "get(2): " << lRUCache.get(2) << endl; // returns -1 (not found)

    cout << "put(4, 4)" << endl;
    lRUCache.put(4, 4); // LRU key 1 is removed, cache is {4,4}, {3,3}

    cout << "get(1): " << lRUCache.get(1) << endl; // returns -1 (not found)
    cout << "get(3): " << lRUCache.get(3) << endl; // returns 3
    // cache is {3,3}, {4,4}

    cout << "get(4): " << lRUCache.get(4) << endl; // returns 4
    // cache is {4,4}, {3,3}

    return 0;
}