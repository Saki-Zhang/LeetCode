// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/

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
// iterative approach
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = 0;
        double diff = numeric_limits<double> :: max();
        
        TreeNode* curr = root;
        
        while(curr != NULL) {
            if(curr -> val == target) {
                return curr -> val;
            }
            
            if(abs(curr -> val - target) < diff) {
                result = curr -> val;
                diff = abs(curr -> val - target);
            }
            
            if(curr -> val > target) {
                curr = curr -> left;
            }
            else {
                curr = curr -> right;
            }
        }
        
        return result;
    }
};

// recursive approach
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = 0;
        double diff = numeric_limits<double> :: max();
        closestValue(root, target, diff, result);
        return result;
    }
    
    void closestValue(TreeNode* root, double target, double& diff, int& result) {
        if(root == NULL) {
            return;
        }
        
        if(abs(root -> val - target) < diff) {
            result = root -> val;
            diff = abs(root -> val - target);
        }
        
        if(root -> val > target) {
            closestValue(root -> left, target, diff, result);
        }
        else if(root -> val < target) {
            closestValue(root -> right, target, diff, result);
        }
    }
};