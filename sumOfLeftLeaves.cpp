// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root, bool is_left) {
        if(root == NULL) {
            return 0;
        }
        
        if(root -> left == NULL && root -> right == NULL && is_left) {
            return root -> val;
        }
        
        return sumOfLeftLeaves(root -> left, true) + sumOfLeftLeaves(root -> right, false);
    }
};