// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> result;
        vector<int> curr;
        
        combine(candidates, target, 0, curr, result);
        
        return result;
    }
    
    void combine(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& result) {
        if(target == 0 && curr.size() != 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = start;i < candidates.size();i ++) {
            if(candidates[i] > target) {
                break;
            }
            
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            curr.push_back(candidates[i]);
            combine(candidates, target - candidates[i], i + 1, curr, result);
            curr.pop_back();
        }
    }
};