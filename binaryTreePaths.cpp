// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string curr = "";
        binaryTreePaths(root, curr, result);
        return result;
    }
    
    void binaryTreePaths(TreeNode* root, string& curr, vector<string>& result) {
        if(root == NULL) {
            return;
        }
        
        string temp = curr;
        curr += to_string(root -> val);
        
        if(root -> left == NULL && root -> right == NULL) {
            result.push_back(curr);
        }
        
        curr += "->";
        
        binaryTreePaths(root -> left, curr, result);
        binaryTreePaths(root -> right, curr, result);
        
        curr = temp;
    }
};