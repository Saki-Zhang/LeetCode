// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

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
// recursive approach (dfs)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        
        return root;
    }
};

// iterative approach (bfs)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            swap(t -> left, t -> right);
            
            if(t -> left != NULL) {
                q.push(t -> left);
            }
            if(t -> right != NULL) {
                q.push(t -> right);
            }
        }
        
        return root;
    }
};