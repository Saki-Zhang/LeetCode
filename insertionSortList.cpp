// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        
        while(curr != NULL) {
            ListNode* sorted = dummy;
            while(sorted -> next != NULL && sorted -> next -> val < curr -> val) {
                sorted = sorted -> next;
            }
            
            ListNode* next = curr -> next;
            curr -> next = sorted -> next;
            sorted -> next = curr;
            curr = next;
        }
        
        return dummy -> next;
    }
};