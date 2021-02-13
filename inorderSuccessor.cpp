// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative approach
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL) {
            return NULL;
        }
        
        TreeNode* curr = root;
        TreeNode* next = NULL; // candidate inorder successor
        
        while(curr != NULL) {
            if(curr -> val > p -> val) {
                // p's inorder successor could not be on the right subtree
                // curr could be p's inorder successor
                next = curr;
                curr = curr -> left;
            }
            else {
                // p's inorder successor could not be on the left subtree
                // curr could not be p's inorder successor
                curr = curr -> right;
            }
        }
        
        return next;
    }
};

// recursive approach
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL) {
            return NULL;
        }
        
        if(root -> val <= p -> val) {
            return inorderSuccessor(root -> right, p);
        }
        
        TreeNode* l = inorderSuccessor(root -> left, p);
        
        return l == NULL ? root : l;
    }
};