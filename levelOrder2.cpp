// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            vector<int> level;
            
            for(int i = q.size();i > 0;i --) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t -> val);
                
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
            
            result.push_back(level);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};