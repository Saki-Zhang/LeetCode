// 687. Longest Univalue Path
// https://leetcode.com/problems/longest-univalue-path/

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
    int longestUnivaluePath(TreeNode* root) {
        int max_length = 0;
        longestUnivaluePath(root, max_length);
        return max_length;
    }
    
    int longestUnivaluePath(TreeNode* root, int& max_length) {
        if(root == NULL) {
            return 0;
        }
        
        int l = longestUnivaluePath(root -> left, max_length);
        int r = longestUnivaluePath(root -> right, max_length);
        
        l = (root -> left != NULL && root -> left -> val == root -> val) ? l + 1 : 0;
        r = (root -> right != NULL && root -> right -> val == root -> val) ? r + 1 : 0;
        
        max_length = max(max_length, l + r);
        
        return max(l, r);
    }
};