// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) {
            return;
        }
        
        inorderTraversal(root -> left, inorder);
        inorder.push_back(root -> val);
        inorderTraversal(root -> right, inorder);
    }
};

// iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        
        TreeNode* curr = root;
        stack<TreeNode*> s;
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            inorder.push_back(curr -> val);
            curr = curr -> right;
        }
        
        return inorder;
    }
};