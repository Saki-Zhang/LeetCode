// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return;
        }
        
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = reverseList(mid);
        
        while(l1 != NULL) {
            ListNode* next1 = l1 -> next;
            ListNode* next2 = l2 -> next;
            
            l1 -> next = l2;
            if(next1 != NULL) { // l2 might have at most one element more than l1
                l2 -> next = next1;
            }
            
            l1 = next1;
            l2 = next2; 
        }
    }
    
    // find the middle node and split the list
    ListNode* middleNode(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if(prev != NULL) {
            prev -> next = NULL;
        }
        
        return slow;
    }
    
    // reverse the list
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