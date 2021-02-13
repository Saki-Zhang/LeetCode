// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode* root) {
        return height(root) != INT_MIN;
    }
    
    int height(TreeNode* root) {
        if(root == NULL) {
            return -1;
        }
        
        int l = height(root -> left); // height of the left subtree
        int r = height(root -> right); // height of the right subtree
        
        // return INT_MIN if the tree is unbalanced, instead of actual height
        if(l == INT_MIN || r == INT_MIN || abs(l - r) > 1) {
            return INT_MIN;
        }
        
        return max(l, r) + 1;
    }
};