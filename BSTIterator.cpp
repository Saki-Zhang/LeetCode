// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
private:
    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    void pushLeft(TreeNode* root) {
        while(root != NULL) {
            s.push(root);
            root = root -> left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        pushLeft(curr -> right);
        
        return curr -> val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */