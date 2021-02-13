// 146. LRU Cache
// https://leetcode.com/problems/lru-cache/

class LRUCacheNode {
public:
    int key;
    int value;
    LRUCacheNode* prev;
    LRUCacheNode* next;
    LRUCacheNode(int key, int value, LRUCacheNode* prev = NULL, LRUCacheNode* next = NULL) : key(key), value(value), prev(prev), next(next) {}
};

class LRUCache {
private:
    int capacity;
    int size;
    LRUCacheNode* head;
    LRUCacheNode* tail;
    unordered_map<int, LRUCacheNode*> cache_map;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
        
        head = new LRUCacheNode(-1, -1);
        tail = new LRUCacheNode(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache_map.find(key) == cache_map.end()) {
            return -1;
        }
        
        int value = remove(cache_map[key]);
        append(key, value);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cache_map.find(key) != cache_map.end()) {
            remove(cache_map[key]);
        }
        
        if(size == capacity) {
            remove(head -> next);
        }
        
        append(key, value);
    }
    
    void append(int key, int value) {
        LRUCacheNode* node = new LRUCacheNode(key, value, tail -> prev, tail);
        tail -> prev -> next = node;
        tail -> prev = node;
        
        size ++;
        cache_map[key] = node;
    }
    
    int remove(LRUCacheNode* node) {
        if(node == NULL) {
            return -1;
        }
        
        int key = node -> key;
        int value = node -> value;
        
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        delete node;
        
        size --;
        cache_map.erase(key);
        
        return value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */