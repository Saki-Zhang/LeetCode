// 366. Find Leaves of Binary Tree
// https://leetcode.com/problems/find-leaves-of-binary-tree/

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        height(root, result);
        return result;
    }
    
    int height(TreeNode* root, vector<vector<int>>& result) {
        if(root == NULL) {
            return -1;
        }
        
        int l = height(root -> left, result);
        int r = height(root -> right, result);
        int h = max(l, r) + 1;
        
        if(h >= result.size()) {
            result.resize(h + 1);
        }
        
        result[h].push_back(root -> val);
        
        return h;
    }
};