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
    void reorderList(ListNode* head) {
        ListNode *slow = head ; 
        ListNode *fast = head ; 
        while ( fast != NULL && fast -> next != NULL ) { 
            fast = fast->next->next ; 
            slow = slow -> next ; 
        }
        ListNode *current = slow -> next ; 
        slow -> next = NULL ; 
        ListNode *prev = NULL ; 
        ListNode *next = NULL ; 
        while ( current != NULL ) { 
            next = current -> next ; 
            current -> next = prev ; 
            prev = current ; 
            current = next ; 
        } 
        ListNode *temp1 = head ; 
        ListNode *temp2 = prev ; 
        while ( temp1 != NULL && temp2 != NULL ) { 
            ListNode *firstnext = temp1 -> next ; 
            ListNode *secondnext = temp2 -> next ;  
            temp1 -> next = temp2 ; 
            temp2 -> next = firstnext ; 
            temp1 = firstnext ; 
            temp2 = secondnext ; 
        }
    }
};