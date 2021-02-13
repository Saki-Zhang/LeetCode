// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        for(int i = 0;i < nums.size();i ++) {
            int j = abs(nums[i]) - 1;
            if(nums[j] < 0) {
                result.push_back(j + 1);
            }
            nums[j] *= -1;
        }
        
        return result;
    }
};