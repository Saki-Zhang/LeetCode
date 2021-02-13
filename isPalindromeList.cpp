// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = reverseList(mid);
        
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val != l2 -> val) {
                return false;
            }
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        return true;
    }
    
    // find the middle node
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
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