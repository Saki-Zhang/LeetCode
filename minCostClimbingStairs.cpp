// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        for(int i = 2;i < n;i ++) {
            cost[i] += min(cost[i - 2], cost[i - 1]);
        }
        
        return min(cost[n - 2], cost[n - 1]);
    }
};