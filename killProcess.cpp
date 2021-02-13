// 582. Kill Process
// https://leetcode.com/problems/kill-process/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        
        unordered_map<int, vector<int>> children;
        queue<int> q;
        
        // use a map to store the tree
        for(int i = 0;i < pid.size();i ++) {
            children[ppid[i]].push_back(pid[i]);
        }
        
        // bfs starting from the first process to kill
        q.push(kill);
        
        while(!q.empty()) {
            int p = q.front();
            q.pop();
            result.push_back(p);
            
            for(int c : children[p]) {
                q.push(c);
            }
        }
        
        return result;
    }
};