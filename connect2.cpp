// 117. Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return NULL;
        }
        
        Node* head = new Node(); // head of next level
        Node* prev = head;
        Node* curr = root;
        
        // establish the next pointers for level N while we are still on level N - 1
        while(curr != NULL) {
            if(curr -> left != NULL) {
                prev -> next = curr -> left;
                prev = prev -> next;
            }
            if(curr -> right != NULL) {
                prev -> next = curr -> right;
                prev = prev -> next;
            }
            
            curr = curr -> next;
        }
        
        connect(head -> next); // start from the leftmost node on the next level
        
        return root;
    }
};