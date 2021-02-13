// 426. Convert Binary Search Tree to Sorted Doubly Linked List
// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// recursive approach
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = NULL;
        Node* tail = NULL;
        
        treeToDoublyList(root, head, tail);
        
        if(tail != NULL) {
            head -> left = tail;
            tail -> right = head;
        }
        
        return head;
    }
    
    void treeToDoublyList(Node* root, Node*& head, Node*& tail) {
        if(root == NULL) {
            return;
        }
        
        treeToDoublyList(root -> left, head, tail);
        
        if(tail != NULL) {
            root -> left = tail;
            tail -> right = root;
        }
        else {
            head = root;
        }
        
        tail = root;
        
        treeToDoublyList(root -> right, head, tail);
    }
};

// iterative approach
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* head = NULL;
        Node* curr = root;
        Node* tail = NULL;
        
        stack<Node*> s;
        
        while(curr != NULL || !s.empty()) {
            while(curr != NULL) {
                s.push(curr);
                curr = curr -> left;
            }
            
            curr = s.top();
            s.pop();
            
            if(tail != NULL) {
                curr -> left = tail;
                tail -> right = curr;
            }
            else {
                head = curr;
            }
            
            tail = curr;
            curr = curr -> right;
        }
        
        if(tail != NULL) {
            head -> left = tail;
            tail -> right = head;
        }
        
        return head;
    }
};