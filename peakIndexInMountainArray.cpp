// 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size() == 0) {
            return -1;
        }
        
        int l = 0;
        int r = arr.size() - 1;
        
        while(l < r) {
            int m = l + (r - l) / 2;
            
            if(arr[m] < arr[m + 1]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        
        return l;
    }
};