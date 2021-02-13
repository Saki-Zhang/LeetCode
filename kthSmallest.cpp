// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        stack<TreeNode*> s;
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            if(-- k == 0) {
                return curr -> val;
            }
            
            curr = curr -> right;
        }
        
        return 0;
    }
};