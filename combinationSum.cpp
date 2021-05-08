// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                continue;
            }
            
            curr.push_back(candidates[i]);
            combine(candidates, target - candidates[i], i, curr, result);
            curr.pop_back();
        }
    }
};