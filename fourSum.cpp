// 18. 4Sum
// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int i = 0;i < nums.size();i ++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for(int j = i + 1;j < nums.size();j ++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int l = j + 1;
                int r = nums.size() - 1;
                
                while(l < r) {
                    if(nums[i] + nums[j] + nums[l] + nums[r] < target || (l > j + 1 && nums[l] == nums[l - 1])) {
                        l ++;
                    }
                    else if(nums[i] + nums[j] + nums[l] + nums[r] > target || (r < nums.size() - 1 && nums[r] == nums[r + 1])) {
                        r --;
                    }
                    else {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l ++;
                        r --;
                    }
                }
            }
        }
        
        return result;
    }
};