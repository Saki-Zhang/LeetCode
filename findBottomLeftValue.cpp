// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0;i < size;i ++) {
                TreeNode* t = q.front();
                q.pop();
                
                if(i == 0) {
                    result = t -> val;
                }
                
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
        }
        
        return result;
    }
};

// recursive approach (dfs)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        int depth = -1;
        findBottomLeftValue(root, 0, depth, result);
        return result;
    }
    
    void findBottomLeftValue(TreeNode* root, int level, int& depth, int& result) {
        if(root == NULL) {
            return;
        }
        
        if(level > depth) {
            result = root -> val;
            depth = level;
        }
        
        findBottomLeftValue(root -> left, level + 1, depth, result);
        findBottomLeftValue(root -> right, level + 1, depth, result);
    }
};