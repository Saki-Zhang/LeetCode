// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* tail = dummy;
        ListNode* curr = head;
        
        int i = 0;
        
        for(;i < m - 1;i ++) {
            tail = curr;
            curr = curr -> next;
        }
        
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        for(;i < n;i ++) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        tail -> next -> next = curr;
        tail -> next = prev;
        
        return dummy -> next;
    }
};