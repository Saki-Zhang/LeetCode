// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> N (T.size(), 0);
        stack<int> s;
        
        for(int i = 0;i < T.size();i ++) {
            while(!s.empty() && T[i] > T[s.top()]) {
                N[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        
        return N;
    }
};