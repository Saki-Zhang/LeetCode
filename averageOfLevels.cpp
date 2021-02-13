// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            int size = q.size();
            double sum = 0;
            
            for(int i = 0;i < size;i ++) {
                TreeNode* t = q.front();
                q.pop();
                sum += t -> val;
                
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
            
            result.push_back(sum / size);
        }
        
        return result;
    }
};