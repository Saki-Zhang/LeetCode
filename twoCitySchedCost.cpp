// 1029. Two City Scheduling
// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    static bool cmp(vector<int>& u, vector<int>& v) {
        return u[0] - u[1] < v[0] - v[1];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        
        int result = 0;
        int n = costs.size() / 2;
        
        for(int i = 0;i < costs.size();i ++) {
            result += i < n ? costs[i][0] : costs[i][1];
        }
        
        return result;
    }
};