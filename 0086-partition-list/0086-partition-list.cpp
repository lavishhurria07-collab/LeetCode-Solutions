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
        if ( head == NULL || head->next == NULL ) { 
            return head ; 
        }
        ListNode* lesser = new ListNode(-1) ; 
        ListNode* greater = new ListNode(-1) ; 
        ListNode* lesser_head = lesser ; 
        ListNode* greater_head = greater ; 
        ListNode* temp = head ; 
        while ( temp != NULL ) { 
            if ( temp->val >= x ) { 
                greater->next = temp ; 
                greater = greater->next ; 
            }
            else { 
                lesser->next = temp ; 
                lesser = lesser->next ; 
            }
            temp = temp->next ; 
        }
        greater->next = NULL ; 
        greater_head = greater_head->next ; 
        lesser->next = greater_head ; 
        lesser_head = lesser_head->next ; 
        return lesser_head ; 
    }
};