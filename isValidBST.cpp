// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

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
// recursive approach (dfs)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long) INT_MIN - 1, (long) INT_MAX + 1);
    }
    
    bool isValidBST(TreeNode* root, long lower, long upper) {
        if(root == NULL) {
            return true;
        }
        
        if(root -> val <= lower || root -> val >= upper) {
            return false;
        }
        
        return isValidBST(root -> left, lower, root -> val) && isValidBST(root -> right, root -> val, upper);
    }
};

// iterative approach (inorder traversal)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long prev = (long) INT_MIN - 1;
        
        TreeNode* curr = root;
        stack<TreeNode*> s;
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            // compare the value of the current node with the previous one
            if(curr -> val <= prev) {
                return false;
            }
            
            prev = curr -> val;
            curr = curr -> right;
        }
        
        return true;
    }
};