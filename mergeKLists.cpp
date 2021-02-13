// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size());
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if(start >= end) {
            return NULL;
        }
        
        if(start == end - 1) {
            return lists[start];
        }
        
        int mid = start + (end - start) / 2;
        ListNode* l = mergeKLists(lists, start, mid);
        ListNode* r = mergeKLists(lists, mid, end);
        
        return mergeLists(l, r);
    }
    
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
};