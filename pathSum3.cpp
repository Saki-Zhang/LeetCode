// 437. Path Sum III
// https://leetcode.com/problems/path-sum-iii/

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
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        int curr = 0;
        
        unordered_map<int, int> sum_cnt; // prefix sum
        sum_cnt[0] = 1;
        
        pathSum(root, sum, curr, result, sum_cnt);
        
        return result;
    }
    
    void pathSum(TreeNode* root, int sum, int& curr, int& result, unordered_map<int, int>& sum_cnt) {
        if(root == NULL) {
            return;
        }
        
        curr += root -> val;
        result += sum_cnt[curr - sum];
        sum_cnt[curr] ++;
        
        pathSum(root -> left, sum, curr, result, sum_cnt);
        pathSum(root -> right, sum, curr, result, sum_cnt);
        
        sum_cnt[curr] --;
        curr -= root -> val;
    }
};