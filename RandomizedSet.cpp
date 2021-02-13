// 380. Insert Delete GetRandom O(1)
// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    vector<int> value_set;
    unordered_map<int, int> index_map;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index_map.find(val) != index_map.end()) {
            return false;
        }
        
        value_set.push_back(val);
        index_map[val] = value_set.size() - 1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index_map.find(val) == index_map.end()) {
            return false;
        }
        
        int i = index_map[val];
        
        // replace value_set[i] with the last element and update the index map
        value_set[i] = value_set.back();
        index_map[value_set[i]] = i;
        
        // remove the last element from both the value set and the index map
        value_set.pop_back();
        index_map.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(value_set.empty()) {
            return -1;
        }
        
        int i = rand() % value_set.size();
        return value_set[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */