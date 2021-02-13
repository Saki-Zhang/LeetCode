// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        unordered_map<int, vector<int>> cols; // store the nodes on each column
        queue<pair<TreeNode*, int>> q; // {node, column}
        
        int min_c = INT_MAX; // minimum column index
        int max_c = INT_MIN; // maximum column index
        
        if(root != NULL) {
            q.push({root, 0});
        }
        
        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            TreeNode* t = p.first;
            int c = p.second;
            cols[c].push_back(t -> val);
            
            min_c = min(min_c, c);
            max_c = max(max_c, c);
            
            if(t -> left != NULL) {
                q.push({t -> left, c - 1});
            }
            if(t -> right != NULL) {
                q.push({t -> right, c + 1});
            }
        }
        
        for(int i = min_c;i <= max_c;i ++) {
            result.push_back(cols[i]);
        }
        
        return result;
    }
};