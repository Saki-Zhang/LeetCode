// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            
            if(result.size() % 2 == 1) {
                reverse(level.begin(), level.end());
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};