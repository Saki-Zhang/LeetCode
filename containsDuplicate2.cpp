// 219. Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> pos;
        
        for(int i = 0;i < nums.size();i ++) {
            if(pos.find(nums[i]) != pos.end() && i - pos[nums[i]] <= k) {
                return true;
            }
            pos[nums[i]] = i;
        }
        
        return false;
    }
};