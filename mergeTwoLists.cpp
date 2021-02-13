// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

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
// recursive approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        
        if(l1 -> val < l2 -> val) {
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
        else {
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};

// iterative approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* l = dummy;
        
        while(l1 != NULL && l2 != NULL) {
            if(l1 -> val < l2 -> val) {
                l -> next = l1;
                l1 = l1 -> next;
            }
            else {
                l -> next = l2;
                l2 = l2 -> next;
            }
            
            l = l -> next;
        }
        
        if(l1 != NULL) {
            l -> next = l1;
        }
        else {
            l -> next = l2;
        }
        
        return dummy -> next;
    }
};