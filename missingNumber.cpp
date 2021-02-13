// 268. Missing Number
// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int target = (n + 1) * n / 2;
        
        for(int num : nums) {
            sum += num;
        }
        
        return target - sum;
    }
};