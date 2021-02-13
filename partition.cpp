// 86. Partition List
// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* headA = new ListNode();
        ListNode* headB = new ListNode();
        
        ListNode* tailA = headA;
        ListNode* tailB = headB;
        
        ListNode* curr = head;
        
        while(curr != NULL) {
            if(curr -> val < x) {
                tailA -> next = curr;
                tailA = tailA -> next;
            }
            else {
                tailB -> next = curr;
                tailB = tailB -> next;
            }
            
            curr = curr -> next;
        }
        
        tailA -> next = headB -> next;
        tailB -> next = NULL;
        
        return headA -> next;
    }
};