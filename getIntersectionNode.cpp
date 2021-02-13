// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// hashset - space complexity: O(m) or O(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        
        ListNode* curr = headA;
        while(curr != NULL) {
            s.insert(curr);
            curr = curr -> next;
        }
        
        curr = headB;
        while(curr != NULL) {
            if(s.find(curr) != s.end()) {
                return curr;
            }
            curr = curr -> next;
        }
        
        return NULL;
    }
};

// two pointers - space complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        // move both pointers one step forward at a time
        // redirect currA to headB when it reaches the end of A
        // redirect currB to headA when it reaches the end of B
        // therefore they are guaranteed to reach the intersection node (or NULL pointer) at the same time
        
        while(currA != currB) {
            if(currA == NULL) {
                currA = headB;
            }
            else {
                currA = currA -> next;
            }
            
            if(currB == NULL) {
                currB = headA;
            }
            else {
                currB = currB -> next;
            }
        }
        
        return currA;
    }
};