// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            vector<int> level;
            
            for(int i = q.size();i > 0;i --) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t -> val);
                
                if(t -> left != NULL) {
                    q.push(t -> left);
                }
                if(t -> right != NULL) {
                    q.push(t -> right);
                }
            }
            
            int max_value = *max_element(level.begin(), level.end());
            result.push_back(max_value);
        }
        
        return result;
    }
};