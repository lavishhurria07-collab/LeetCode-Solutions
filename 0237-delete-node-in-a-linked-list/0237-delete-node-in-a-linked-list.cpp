/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int value = node->next->val ; 
        node->val = value ; 
        ListNode* dummy = node->next ; 
        node->next = dummy->next ; 
        delete dummy ; 
    }
};