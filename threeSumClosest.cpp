// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        int diff = INT_MAX;
        
        for(int i = 0;i < nums.size();i ++) {
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum < target) {
                    l ++;
                }
                else if(sum > target) {
                    r --;
                }
                else {
                    return sum;
                }
                
                if(abs(sum - target) < diff) {
                    result = sum;
                    diff = abs(sum - target);
                }
            }
        }
        
        return result;
    }
};