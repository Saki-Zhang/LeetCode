// 298. Binary Tree Longest Consecutive Sequence
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    int longestConsecutive(TreeNode* root) {
        int result = 0;
        longestConsecutive(root, result);
        return result;
    }
    
    int longestConsecutive(TreeNode* root, int& result) {
        if(root == NULL) {
            return 0;
        }
        
        int length = 1;
        int l = longestConsecutive(root -> left, result);
        int r = longestConsecutive(root -> right, result);
        
        if(root -> left != NULL && root -> val == root -> left -> val - 1) {
            length = max(length, l + 1);
        }
        if(root -> right != NULL && root -> val == root -> right -> val - 1) {
            length = max(length, r + 1);
        }
        
        result = max(result, length);
        
        return length;
    }
};