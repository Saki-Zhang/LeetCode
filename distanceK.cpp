// 863. All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(root, NULL, graph);
        
        vector<int> result;
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(target);
        visited.insert(target);
        
        K ++;
        
        while(!q.empty() && K --) {
            for(int i = q.size();i > 0;i --) {
                TreeNode* t = q.front();
                q.pop();
                
                if(K == 0) {
                    result.push_back(t -> val);
                }
                
                for(TreeNode* n : graph[t]) {
                    if(visited.find(n) == visited.end()) {
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }
        }
        
        return result;
    }
    
    void dfs(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if(root == NULL) {
            return;
        }
        
        if(parent != NULL) {
            graph[parent].push_back(root);
            graph[root].push_back(parent);
        }
        
        dfs(root -> left, root, graph);
        dfs(root -> right, root, graph);
    }
};