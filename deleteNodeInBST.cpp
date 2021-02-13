// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        }
        else if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        }
        else {
            if(root -> left == NULL && root -> right == NULL) {
                // if the node to delete is a leaf
                // just set it to NULL
                root = NULL;
            }
            else if(root -> left != NULL) {
                // if the node has a left child
                // replace the node with its predecessor
                // and delete the predecessor in the left subtree recursively
                TreeNode* curr = root -> left;
                while(curr -> right != NULL) {
                    curr = curr -> right;
                }
                
                root -> val = curr -> val;
                root -> left = deleteNode(root -> left, root -> val);
            }
            else {
                // if the node has a right child
                // replace the node with its successor
                // and delete the successor in the right subtree recursively
                TreeNode* curr = root -> right;
                while(curr -> left != NULL) {
                    curr = curr -> left;
                }
                
                root -> val = curr -> val;
                root -> right = deleteNode(root -> right, root -> val);
            }
        }
        
        return root;
    }
};