// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index_map;
        
        for(int i = 0;i < inorder.size();i ++) {
            index_map[inorder[i]] = i;
        }
        
        return buildTree(inorder, postorder, index_map, 0, inorder.size(), 0, postorder.size());
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& index_map, int in_start, int in_end, int post_start, int post_end) {
        if(in_start >= in_end || post_start >= post_end) {
            return NULL;
        }
        
        int val = postorder[post_end - 1];
        int idx = index_map[val];
        
        TreeNode* root = new TreeNode(val);
        root -> left = buildTree(inorder, postorder, index_map, in_start, idx, post_start, post_start + (idx - in_start));
        root -> right = buildTree(inorder, postorder, index_map, idx + 1, in_end, post_start + (idx - in_start), post_end - 1);
        
        return root;
    }
};