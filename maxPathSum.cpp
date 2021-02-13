// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        pathSum(root, max_sum);
        return max_sum;
    }
    
    int pathSum(TreeNode* root, int& max_sum) {
        if(root == NULL) {
            return 0;
        }
        
        int l = max(pathSum(root -> left, max_sum), 0);
        int r = max(pathSum(root -> right, max_sum), 0);
        
        max_sum = max(max_sum, root -> val + l + r);
        
        return root -> val + max(l, r);
    }
};