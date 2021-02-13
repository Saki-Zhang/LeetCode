// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
// iterative approach (bfs)
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; // {node, depth}
        
        if(root != NULL) {
            q.push({root, 1});
        }
        
        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            TreeNode* t = p.first;
            int d = p.second;
            
            if(t -> left == NULL && t -> right == NULL) {
                return d;
            }
            
            if(t -> left != NULL) {
                q.push({t -> left, d + 1});
            }
            if(t -> right != NULL) {
                q.push({t -> right, d + 1});
            }
        }
        
        return 0;
    }
};

// recursive approach (dfs)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        if(root -> left == NULL) {
            return minDepth(root -> right) + 1;
        }
        if(root -> right == NULL) {
            return minDepth(root -> left) + 1;
        }
        
        return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};