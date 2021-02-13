// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        
        int l = 0;
        
        ListNode* curr = head;
        ListNode* tail = NULL;
        
        while(curr != NULL) {
            tail = curr;
            curr = curr -> next;
            l ++;
        }
        
        tail -> next = head;
        curr = tail;
        
        k = l - k % l;
        
        while(k > 0) {
            curr = curr -> next;
            k --;
        }
        
        ListNode* new_tail = curr;
        ListNode* new_head = curr -> next;
        
        new_tail -> next = NULL;
        
        return new_head;
    }
};