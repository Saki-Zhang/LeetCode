// 742. Closest Leaf in a Binary Tree
// https://leetcode.com/problems/closest-leaf-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        TreeNode* start = NULL;
        
        // build the graph using dfs and find the target node
        dfs(root, k, NULL, start, graph);
        
        // use bfs to find the closest leaf to the target node
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        if(start != NULL) {
            q.push(start);
            visited.insert(start);
        }
        
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            
            if(t -> left == NULL && t -> right == NULL) {
                return t -> val;
            }
            
            for(TreeNode* n : graph[t]) {
                if(visited.find(n) == visited.end()) {
                    q.push(n);
                    visited.insert(n);
                }
            }
        }
        
        return 0;
    }
    
    void dfs(TreeNode* root, int k, TreeNode* parent, TreeNode*& start, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if(root == NULL) {
            return;
        }
        
        if(root -> val == k) {
            start = root;
        }
        
        if(parent != NULL) {
            graph[parent].push_back(root);
            graph[root].push_back(parent);
        }
        
        dfs(root -> left, k, root, start, graph);
        dfs(root -> right, k, root, start, graph);
    }
};