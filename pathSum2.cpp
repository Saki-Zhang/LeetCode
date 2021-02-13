// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> curr;
        pathSum(root, sum, curr, result);
        return result;
    }
    
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& result) {
        if(root == NULL) {
            return;
        }
        
        curr.push_back(root -> val);
        
        if(root -> left == NULL && root -> right == NULL && root -> val == sum) {
            result.push_back(curr);
        }
        
        pathSum(root -> left, sum - root -> val, curr, result);
        pathSum(root -> right, sum - root -> val, curr, result);
        
        curr.pop_back();
    }
};