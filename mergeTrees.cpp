// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) {
            return t2;
        }
        if(t2 == NULL) {
            return t1;
        }
        
        TreeNode* root = new TreeNode(
            t1 -> val + t2 -> val,
            mergeTrees(t1 -> left, t2 -> left),
            mergeTrees(t1 -> right, t2 -> right)
            );
        
        return root;
    }
};