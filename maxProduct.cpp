// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int max_product = INT_MIN;
        int curr_max = 1;
        int curr_min = 1;
        
        for(int num : nums) {
            int new_max = max(max(curr_max * num, curr_min * num), num);
            int new_min = min(min(curr_max * num, curr_min * num), num);
            
            curr_max = new_max;
            curr_min = new_min;
            
            max_product = max(max_product, curr_max);
        }
        
        return max_product;
    }
};