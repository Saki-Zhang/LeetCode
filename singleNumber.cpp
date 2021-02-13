// 136. Single Number
// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        // bit manipulation
        for(int num : nums) {
            result ^= num; // XOR
        }
        
        return result;
    }
};