// 250. Count Univalue Subtrees
// https://leetcode.com/problems/count-univalue-subtrees/

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
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        isUnivalTree(root, result);
        return result;
    }
    
    bool isUnivalTree(TreeNode* root, int& result) {
        if(root == NULL) {
            return true;
        }
        
        bool flag = true;
        bool l = isUnivalTree(root -> left, result); // check if left subtree is a uni-value tree
        bool r = isUnivalTree(root -> right, result); // check if right subtree is a uni-value tree
        
        if(root -> left != NULL) {
            flag &= (root -> left -> val == root -> val && l);
        }
        if(root -> right != NULL) {
            flag &= (root -> right -> val == root -> val && r);
        }
        
        result += flag ? 1 : 0;
        
        return flag;
    }
};