// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s;
        
        for(int num : nums1) {
            s.insert(num);
        }
        
        for(int num : nums2) {
            if(s.find(num) != s.end()) {
                result.push_back(num);
                s.erase(num);
            }
        }
        
        return result;
    }
};