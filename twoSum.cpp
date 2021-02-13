// 1. Two Sum
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos;
        
        for(int i = 0;i < nums.size();i ++) {
            int num = nums[i];
            int num_to_add = target - num;
            
            if(pos.find(num_to_add) != pos.end()) {
                return {pos[num_to_add], i};
            }
            pos[num] = i;
        }
        
        return {};
    }
};