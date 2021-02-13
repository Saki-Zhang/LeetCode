// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0) {
            return {};
        }
        
        vector<vector<int>> result;
        vector<int> path;
        
        int src = 0;
        int tar = graph.size() - 1;
        
        path.push_back(src);
        backtrack(graph, src, tar, path, result);
        
        return result;
    }
    
    void backtrack(vector<vector<int>>& graph, int node, int target, vector<int>& path, vector<vector<int>>& result) {
        if(node == target) {
            result.push_back(path);
            return;
        }
        
        for(int next : graph[node]) {
            path.push_back(next);
            backtrack(graph, next, target, path, result);
            path.pop_back();
        }
    }
};