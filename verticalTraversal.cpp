// 987. Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        
        map<int, map<int, set<int>>> nodes; // store the nodes at each position (x, y)
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {x, y}}
        
        if(root != NULL) {
            q.push({root, {0, 0}});
        }
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int, int>> p = q.front();
            q.pop();
            
            TreeNode* t = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            nodes[x][y].insert(t -> val);
            
            if(t -> left != NULL) {
                q.push({t -> left, {x - 1, y + 1}});
            }
            if(t -> right != NULL) {
                q.push({t -> right, {x + 1, y + 1}});
            }
        }
        
        for(auto c : nodes) { // for each column
            vector<int> column;
            for(auto r : c.second) { // for each row
                for(auto v : r.second) { // for each value
                    // add the value to its column
                    column.push_back(v);
                }
            }
            // add the column to result
            result.push_back(column);
        }
        
        return result;
    }
};