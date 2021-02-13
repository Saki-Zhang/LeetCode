// 369. Plus One Linked List
// https://leetcode.com/problems/plus-one-linked-list/

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
    ListNode* plusOne(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        
        ListNode* curr = head;
        ListNode* last = NULL; // the last non-nine digit
        
        while(curr != NULL) {
            if(curr -> val != 9) {
                last = curr;
            }
            curr = curr -> next;
        }
        
        // create a new head with a value of 0 on the left when all digits are 9
        if(last == NULL) {
            head = new ListNode(0, head);
            last = head;
        }
        
        last -> val ++; // increase the last non-nine digit by 1
        curr = last -> next;
        
        // set all the following nines to 0
        while(curr != NULL) {
            curr -> val = 0;
            curr = curr -> next;
        }
        
        return head;
    }
};