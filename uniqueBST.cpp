// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        vector<int> numBST (n + 1, 0);
        
        numBST[0] = 1;
        numBST[1] = 1;
        
        // i: number of nodes in the tree
        // l: number of nodes in the left subtree
        // r: number of nodes in the right subtree
        for(int i = 2;i <= n;i ++) {
            for(int l = 0;l <= i - 1;l ++) {
                int r = i - 1 - l;
                numBST[i] += numBST[l] * numBST[r];
            }
        }
        
        return numBST[n];
    }
};