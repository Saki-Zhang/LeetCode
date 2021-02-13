// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }
    
    void reverse(vector<int>& nums, int start, int end) {
        int l = start;
        int r = end - 1;
        
        while(l < r) {
            swap(nums[l ++], nums[r --]);
        }
    }
};