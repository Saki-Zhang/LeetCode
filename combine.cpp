// 77. Combinations
// https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        combine(n, k, 1, curr, result);
        return result;
    }
    
    void combine(int n, int k, int start, vector<int>& curr, vector<vector<int>>& result) {
        if(curr.size() == k) {
            result.push_back(curr);
            return;
        }
        
        for(int i = start;i <= n;i ++) {
            curr.push_back(i);
            combine(n, k, i + 1, curr, result);
            curr.pop_back();
        }
    }
};