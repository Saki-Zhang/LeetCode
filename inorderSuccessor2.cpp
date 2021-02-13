// 510. Inorder Successor in BST II
// https://leetcode.com/problems/inorder-successor-in-bst-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // if node has a right child
        // return the leftmost node on the right subtree
        if(node != NULL && node -> right != NULL) {
            node = node -> right;
            while(node -> left != NULL) {
                node = node -> left;
            }
            return node;
        }
        
        // if node does not have a right child
        // go up till the node is the left child of its parent and return the parent
        while(node != NULL && node -> parent != NULL) {
            if(node == node -> parent -> left) {
                return node -> parent;
            }
            node = node -> parent;
        }
        
        return NULL;
    }
};