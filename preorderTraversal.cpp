// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
// recursive approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preorderTraversal(root, preorder);
        return preorder;
    }
    
    void preorderTraversal(TreeNode* root, vector<int>& preorder) {
        if(root == NULL) {
            return;
        }
        
        preorder.push_back(root -> val);
        preorderTraversal(root -> left, preorder);
        preorderTraversal(root -> right, preorder);
    }
};

// iterative approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> s;
        
        if(root != NULL) {
            s.push(root);
        }
        
        while(!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            preorder.push_back(t -> val);
            
            if(t -> right != NULL) {
                s.push(t -> right);
            }
            if(t -> left != NULL) {
                s.push(t -> left);
            }
        }
        
        return preorder;
    }
};