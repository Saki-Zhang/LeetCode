// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr != NULL) {
            if(curr -> val != val) {
                prev -> next = curr;
                prev = prev -> next;
            }
            
            curr = curr -> next;
        }
        
        prev -> next = NULL;
        
        return dummy -> next;
    }
};