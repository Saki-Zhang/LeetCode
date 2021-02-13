// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        TreeNode* tail = NULL;
        flatten(root, tail);
    }
    
    void flatten(TreeNode* root, TreeNode*& tail) {
        if(root == NULL) {
            return;
        }
        
        flatten(root -> right, tail);
        flatten(root -> left, tail);
        
        root -> left = NULL;
        root -> right = tail;
        
        tail = root;
    }
};