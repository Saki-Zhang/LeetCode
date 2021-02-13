// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

// space complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result (n);
        vector<int> L (n, 1);
        vector<int> R (n, 1);
        
        for(int i = 1;i < n;i ++) {
            L[i] = L[i - 1] * nums[i - 1];
        }
        
        for(int i = n - 2;i >= 0;i --) {
            R[i] = R[i + 1] * nums[i + 1];
        }
        
        for(int i = 0;i < n;i ++) {
            result[i] = L[i] * R[i];
        }
        
        return result;
    }
};

// space complexity: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int R = 1;
        
        vector<int> result (n, 1);
        
        for(int i = 1;i < n;i ++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        for(int i = n - 1;i >= 0;i --) {
            result[i] *= R;
            R *= nums[i];
        }
        
        return result;
    }
};