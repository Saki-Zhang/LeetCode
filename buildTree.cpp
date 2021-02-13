// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index_map; // use a map to store the index of each value in the inorder list
        
        for(int i = 0;i < inorder.size();i ++) {
            index_map[inorder[i]] = i;
        }
        
        return buildTree(preorder, inorder, index_map, 0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& index_map, int pre_start, int pre_end, int in_start, int in_end) {
        if(pre_start >= pre_end || in_start >= in_end) {
            return NULL;
        }
        
        // the first element in the preorder list is the root
        // split the inorder list by the root
        // construct the left subtree and the right subtree recursively
        
        int val = preorder[pre_start];
        int idx = index_map[val];
        
        TreeNode* root = new TreeNode(val);
        root -> left = buildTree(preorder, inorder, index_map, pre_start + 1, pre_start + 1 + (idx - in_start), in_start, idx);
        root -> right = buildTree(preorder, inorder, index_map, pre_start + 1 + (idx - in_start), pre_end, idx + 1, in_end);
        
        return root;
    }
};