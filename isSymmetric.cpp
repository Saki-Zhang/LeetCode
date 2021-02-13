// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        
        if(p == NULL || q == NULL) {
            return false;
        }
        
        return p -> val == q -> val && isSymmetric(p -> left, q -> right) && isSymmetric(p -> right, q -> left);
    }
};

// iterative approach (bfs)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        q1.push(root);
        q2.push(root);
        
        while(!q1.empty() && !q2.empty()) {
            TreeNode* t1 = q1.front();
            TreeNode* t2 = q2.front();
            
            q1.pop();
            q2.pop();
            
            if(t1 == NULL && t2 == NULL) {
                continue;
            }
            
            if(t1 == NULL || t2 == NULL || t1 -> val != t2 -> val) {
                return false;
            }
            
            q1.push(t1 -> left);
            q1.push(t1 -> right);
            q2.push(t2 -> right);
            q2.push(t2 -> left);
        }
        
        return true;
    }
};