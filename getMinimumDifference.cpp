// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        
        stack<TreeNode*> s;
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            if(prev != NULL) {
                result = min(result, curr -> val - prev -> val);
            }
            
            prev = curr;
            curr = curr -> right;
        }
        
        return result;
    }
};