// 448. Find All Numbers Disappeared in an Array
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        for(int i = 0;i < nums.size();i ++) {
            int j = abs(nums[i]) - 1;
            if(nums[j] > 0) {
                nums[j] *= -1;
            }
        }
        
        for(int i = 0;i < nums.size();i ++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};