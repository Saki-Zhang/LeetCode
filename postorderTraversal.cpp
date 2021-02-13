// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postorderTraversal(root, postorder);
        return postorder;
    }
    
    void postorderTraversal(TreeNode* root, vector<int>& postorder) {
        if(root == NULL) {
            return;
        }
        
        postorderTraversal(root -> left, postorder);
        postorderTraversal(root -> right, postorder);
        postorder.push_back(root -> val);
    }
};

// iterative approach
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> s;
        
        if(root != NULL) {
            s.push(root);
        }
        
        while(!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            postorder.push_back(t -> val);
            
            if(t -> left != NULL) {
                s.push(t -> left);
            }
            if(t -> right != NULL) {
                s.push(t -> right);
            }
        }
        
        reverse(postorder.begin(), postorder.end());
        
        return postorder;
    }
};