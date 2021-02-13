// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

// topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list (numCourses);
        vector<int> in_degree (numCourses, 0);
        vector<int> result;
        queue<int> q;
        
        for(auto p : prerequisites) {
            int prev = p[1];
            int next = p[0];
            
            adj_list[prev].push_back(next);
            in_degree[next] ++;
        }
        
        for(int i = 0;i < numCourses;i ++) {
            if(in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int prev = q.front();
            q.pop();
            result.push_back(prev);
            
            for(int next : adj_list[prev]) {
                in_degree[next] --;
                if(in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if(result.size() != numCourses) {
            return {};
        }
        
        return result;
    }
};