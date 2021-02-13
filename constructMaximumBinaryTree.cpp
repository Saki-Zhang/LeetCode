// 654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size());
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
        if(start >= end) {
            return NULL;
        }
        
        auto it = max_element(nums.begin() + start, nums.begin() + end); // return the iterator pointing to the maximum value
        int idx = it - nums.begin();
        int max_val = *it;
        
        TreeNode* root = new TreeNode(
            max_val,
            constructMaximumBinaryTree(nums, start, idx),
            constructMaximumBinaryTree(nums, idx + 1, end)
            );
        
        return root;
    }
};