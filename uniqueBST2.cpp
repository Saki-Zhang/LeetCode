// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return {};
        }
        
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> result;
        
        if(start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for(int i = start;i <= end;i ++) {
            // use number i as root, generate all possible left and right subtrees
            vector<TreeNode*> L = generateTrees(start, i - 1);
            vector<TreeNode*> R = generateTrees(i + 1, end);
            
            for(auto l : L) {
                for(auto r : R) {
                    TreeNode* root = new TreeNode(i, l, r);
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
};