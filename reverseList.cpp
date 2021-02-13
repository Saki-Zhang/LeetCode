// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

// recursive approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode* rest = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return rest;
    }
};