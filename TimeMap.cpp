// 981. Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    unordered_map<string, map<int, string>> m;

public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) {
            return "";
        }
        
        auto it = m[key].upper_bound(timestamp); // return an iterator pointing to the first element whose key is greater than the given timestamp
        
        return it == m[key].begin() ? "" : prev(it) -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */