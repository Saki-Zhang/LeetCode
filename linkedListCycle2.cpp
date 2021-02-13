// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// hashset - space complexity: O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        
        ListNode* curr = head;
        while(curr != NULL) {
            if(s.find(curr) != s.end()) {
                return curr;
            }
            
            s.insert(curr);
            curr = curr -> next;
        }
        
        return NULL;
    }
};

// two pointers - space complexity: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* intersect = hasCycle(head);
        
        if(intersect == NULL) {
            return NULL;
        }
        
        // x: number of nodes outside of the cycle
        // y: number of nodes in the cycle
        
        // when fast and slow meet at the intersection
        // fast moves x + k * y + i steps
        // slow moves x + i steps
        
        // x + k * y + i = 2 * (x + i)
        // x + i = k * y
        // x = (k - 1) * y + j
        
        // set ptr1 to the head and ptr2 to the intersection
        // move both pointers at the same speed
        // they are guaranteed to meet at the start of the cycle
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = intersect;
        
        while(ptr1 != ptr2) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        return ptr1;
    }
    
    ListNode* hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(fast == slow) {
                return fast;
            }
        }
        
        return NULL;
    }
};