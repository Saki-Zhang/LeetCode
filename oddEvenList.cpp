// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        
        ListNode* odd_head = head;
        ListNode* odd_tail = head;
        
        ListNode* even_head = head -> next;
        ListNode* even_tail = head -> next;
        
        while(even_tail != NULL && even_tail -> next != NULL) {
            odd_tail -> next = even_tail -> next;
            odd_tail = odd_tail -> next;
            
            even_tail -> next = odd_tail -> next;
            even_tail = even_tail -> next;
        }
        
        odd_tail -> next = even_head;
        
        return odd_head;
    }
};