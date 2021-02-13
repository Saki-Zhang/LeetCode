// 46. Permutations
// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<int> visited (nums.size(), 0);
        permute(nums, curr, visited, result);
        return result;
    }
    
    void permute(vector<int>& nums, vector<int>& curr, vector<int>& visited, vector<vector<int>>& result) {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        
        for(int i = 0;i < nums.size();i ++) {
            if(visited[i] == 1) {
                continue;
            }
            
            curr.push_back(nums[i]);
            visited[i] = 1;
            
            permute(nums, curr, visited, result);
            
            curr.pop_back();
            visited[i] = 0;
        }
    }
};