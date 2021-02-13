// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            for(int i = q.size();i > 0;i --) {
                TreeNode* t = q.front();
                q.pop();
                
                if(i == 1) {
                    result.push_back(t -> val);
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideView(root, 0, result);
        return result;
    }
    
    void rightSideView(TreeNode* root, int level, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        
        if(level >= result.size()) {
            result.resize(level + 1);
        }
        
        result[level] = root -> val;
        
        rightSideView(root -> left, level + 1, result);
        rightSideView(root -> right, level + 1, result);
    }
};