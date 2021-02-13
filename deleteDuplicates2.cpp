// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr != NULL) {
            while(curr -> next != NULL && curr -> next -> val == curr -> val) {
                curr = curr -> next;
            }
            
            if(prev -> next == curr) { // no duplicates detected
                prev = curr;
                curr = curr -> next;
            }
            else { // duplicates detected
                prev -> next = curr -> next;
                curr = curr -> next;
            }
        }
        
        return dummy -> next;
    }
};

// recursive approach
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        
        if(head -> next != NULL && head -> next -> val == head -> val) {
            while(head -> next != NULL && head -> next -> val == head -> val) {
                head = head -> next;
            }
            return deleteDuplicates(head -> next);
        }
        
        head -> next = deleteDuplicates(head -> next);
        
        return head;
    }
};