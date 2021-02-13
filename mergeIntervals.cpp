// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    static bool cmp(vector<int>& u, vector<int>& v) {
        return u[0] < v[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<vector<int>> result;
        
        for(vector<int> itv : intervals) {
            if(result.empty() || result.back()[1] < itv[0]) {
                result.push_back(itv);
            }
            else {
                result.back()[1] = max(result.back()[1], itv[1]);
            }
        }
        
        return result;
    }
};