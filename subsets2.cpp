// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> curr;
        
        subsets(nums, 0, curr, result);
        
        return result;
    }
    
    void subsets(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);
        
        for(int i = start;i < nums.size();i ++) {
            if(i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            curr.push_back(nums[i]);
            subsets(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
};