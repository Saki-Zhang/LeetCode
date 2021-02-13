// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
// dfs with hashset
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return findTarget(root, k, s);
    }
    
    bool findTarget(TreeNode* root, int k, unordered_set<int>& s) {
        if(root == NULL) {
            return false;
        }
        
        if(s.find(k - root -> val) != s.end()) {
            return true;
        }
        
        s.insert(root -> val);
        
        return findTarget(root -> left, k, s) || findTarget(root -> right, k, s);
    }
};

// inorder traversal
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        int l = 0;
        int r = inorder.size() - 1;
        
        while(l < r) {
            if(inorder[l] + inorder[r] < k) {
                l ++;
            }
            else if(inorder[l] + inorder[r] > k) {
                r --;
            }
            else {
                return true;
            }
        }
        
        return false;
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