// 662. Maximum Width of Binary Tree
// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
// recursive approach (dfs)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        unordered_map<int, int> leftmost; // store the position of the leftmost node of each level
        widthOfBinaryTree(root, 0, 0, result, leftmost);
        return result;
    }
    
    void widthOfBinaryTree(TreeNode* root, int level, int pos, int& result, unordered_map<int, int>& leftmost) {
        if(root == NULL) {
            return;
        }
        
        if(leftmost.find(level) == leftmost.end()) {
            leftmost[level] = pos;
        }
        
        result = max(result, pos - leftmost[level] + 1);
        
        // offset node position
        if(root -> left != NULL) {
            widthOfBinaryTree(root -> left, level + 1, (pos - leftmost[level]) * 2, result, leftmost);
        }
        if(root -> right != NULL) {
            widthOfBinaryTree(root -> right, level + 1, (pos - leftmost[level]) * 2 + 1, result, leftmost);
        }
    }
};

// iterative approach (bfs)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int result = 0;
        int leftmost = 0; // store the position of the leftmost node of each level
        
        queue<pair<TreeNode*, int>> q; // {node, pos}
        
        if(root != NULL) {
            q.push({root, 0});
        }
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0;i < size;i ++) {
                pair<TreeNode*, int> p = q.front();
                q.pop();
                
                TreeNode* t = p.first;
                int pos = p.second;
                
                if(i == 0) {
                    leftmost = pos;
                }
                
                result = max(result, pos - leftmost + 1);
                
                if(t -> left != NULL) {
                    q.push({t -> left, (pos - leftmost) * 2});
                }
                if(t -> right != NULL) {
                    q.push({t -> right, (pos - leftmost) * 2 + 1});
                }
            }
        }
        
        return result;
    }
};