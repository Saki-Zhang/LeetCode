// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curr = 0;
        sumNumbers(root, curr, sum);
        return sum;
    }
    
    void sumNumbers(TreeNode* root, int& curr, int& sum) {
        if(root == NULL) {
            return;
        }
        
        int temp = curr;
        curr = curr * 10 + root -> val;
        
        if(root -> left == NULL && root -> right == NULL) {
            sum += curr;
        }
        
        sumNumbers(root -> left, curr, sum);
        sumNumbers(root -> right, curr, sum);
        
        curr = temp;
    }
};