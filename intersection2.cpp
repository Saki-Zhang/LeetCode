// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        
        for(int num : nums1) {
            m[num] ++;
        }
        
        for(int num : nums2) {
            if(m.find(num) != m.end() && m[num] > 0) {
                result.push_back(num);
                m[num] --;
            }
        }
        
        return result;
    }
};