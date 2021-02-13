// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        height(root, result);
        return result;
    }
    
    int height(TreeNode* root, int& result) {
        if(root == NULL) {
            return 0;
        }
        
        int l = height(root -> left, result);
        int r = height(root -> right, result);
        int h = max(l, r) + 1;
        
        result = max(result, l + r);
        
        return h;
    }
};