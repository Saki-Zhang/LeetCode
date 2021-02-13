// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_cnt; // prefix sum
        sum_cnt[0] = 1;
        
        int result = 0;
        int sum = 0;
        
        for(int num : nums) {
            sum += num;
            result += sum_cnt[sum - k];
            sum_cnt[sum] ++;
        }
        
        return result;
    }
};