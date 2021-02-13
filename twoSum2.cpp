// 167. Two Sum II - Input array is sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 0) {
            return {};
        }
        
        int l = 0;
        int r = numbers.size() - 1;
        
        while(l < r) {
            if(numbers[l] + numbers[r] < target) {
                l ++;
            }
            else if(numbers[l] + numbers[r] > target) {
                r --;
            }
            else {
                return {l + 1, r + 1};
            }
        }
        
        return {};
    }
};