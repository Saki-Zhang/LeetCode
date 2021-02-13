// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, NULL);
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(head == tail) {
            return NULL;
        }
        
        ListNode* mid = middleNode(head, tail);
        
        TreeNode* root = new TreeNode(
            mid -> val,
            sortedListToBST(head, mid),
            sortedListToBST(mid -> next, tail)
            );
        
        return root;
    }
    
    ListNode* middleNode(ListNode* head, ListNode* tail) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != tail && fast -> next != tail) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
};