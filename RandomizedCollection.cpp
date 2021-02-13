// 381. Insert Delete GetRandom O(1) - Duplicates allowed
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
private:
    vector<pair<int, int>> value_set;
    unordered_map<int, vector<int>> index_map;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        value_set.push_back({val, index_map[val].size()});
        index_map[val].push_back(value_set.size() - 1);
        
        return index_map[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(index_map[val].empty()) {
            return false;
        }
        
        int i = index_map[val].back();
        
        value_set[i] = value_set.back();
        index_map[value_set[i].first][value_set[i].second] = i;
        
        value_set.pop_back();
        index_map[val].pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(value_set.empty()) {
            return -1;
        }
        
        int i = rand() % value_set.size();
        return value_set[i].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */