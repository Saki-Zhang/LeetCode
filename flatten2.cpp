// 430. Flatten a Multilevel Doubly Linked List
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tail = NULL;
        flatten(head, tail);
        return head;
    }
    
    void flatten(Node* head, Node*& tail) {
        if(head == NULL) {
            return;
        }
        
        flatten(head -> next, tail);
        flatten(head -> child, tail);
        
        head -> child = NULL;
        head -> next = tail;
        if(tail != NULL) {
            tail -> prev = head;
        }
        
        tail = head;
    }
};