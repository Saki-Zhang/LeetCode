// 170. Two Sum III - Data structure design
// https://leetcode.com/problems/two-sum-iii-data-structure-design/

class TwoSum {
private:
    unordered_map<int, int> cnt;

public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        cnt[number] ++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto p : cnt) {
            if((long) value - p.first < INT_MIN || (long) value - p.first > INT_MAX) {
                continue;
            }
            
            int num = p.first;
            int num_to_add = value - num;
            
            if(cnt.find(num_to_add) != cnt.end()) {
                if(num != num_to_add || cnt[num_to_add] > 1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */