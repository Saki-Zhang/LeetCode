// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

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
// dfs - time complexity: O(n)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

// optimized dfs - time complexity: O(log(n)*log(n))
class Solution {
public:
    int countNodes(TreeNode* root) {
        int hl = 0;
        int hr = 0;
        
        TreeNode* curr = root;
        while(curr != NULL) {
            hl ++;
            curr = curr -> left;
        }
        
        curr = root;
        while(curr != NULL) {
            hr ++;
            curr = curr -> right;
        }
        
        // perfect binary tree
        if(hl == hr) {
            return pow(2, hl) - 1;
        }
        
        // only one recursive call will be triggered
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

// binary search - time complexity: O(log(n)*log(n))
class Solution {
public:
    int countNodes(TreeNode* root) {
        int d = depth(root);
        int l = pow(2, d - 1);
        int h = pow(2, d) - 1;
        
        while(l < h) {
            int m = l + (h - l + 1) / 2; // avoid infinite loop
            
            if(hasK(root, m)) { // the complete tree has at least m nodes
                l = m;
            }
            else { // the complete tree has less than m nodes
                h = m - 1;
            }
        }
        
        return l;
    }
    
    // return the depth of the complete tree
    int depth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        return depth(root -> left) + 1;
    }
    
    // check if the complete tree has k nodes
    bool hasK(TreeNode* root, int k) {
        if(k <= 0) {
            return true;
        }
        
        vector<int> path; // store node indices from root to node k
        
        while(k > 0) {
            path.push_back(k);
            k /= 2;
        }
        
        for(int i = path.size() - 1;i >= 0;i --) {
            if(root == NULL) {
                return false;
            }
            
            if(i == 0) {
                return true;
            }
            
            if(path[i - 1] == path[i] * 2) {
                root = root -> left;
            }
            else {
                root = root -> right;
            }
        }
        
        return true;
    }
};