// 148. Sort List
// https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode* mid = middleNode(head);
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        
        return mergeLists(l1, l2);
    }
    
    // merge two sorted lists
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeLists(l1 -> next, l2);
            return l1;
        }
        else {
            l2 -> next = mergeLists(l1, l2 -> next);
            return l2;
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
};