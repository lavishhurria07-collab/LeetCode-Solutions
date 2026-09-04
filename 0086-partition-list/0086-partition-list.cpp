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
    ListNode* partition(ListNode* head, int x) {; 
        if ( head == NULL || head -> next == NULL ) { 
            return head ; 
        }
        ListNode *first_dummy = new ListNode(0) ; 
        ListNode *second_dummy = new ListNode(0) ; 
        ListNode *first = first_dummy ; 
        ListNode *second = second_dummy ;  
        ListNode *temp = head ; 
        first_dummy -> next = first ; 
        second_dummy -> next = second ;
        while ( temp != NULL ) { 
            ListNode *attach = temp -> next ;
            if ( temp -> val < x ) { 
                first -> next = temp ; 
                first = first -> next ; 
            }
            else { 
                second -> next = temp ; 
                second = second -> next ; 
            }
            attach = temp ;
            temp = temp -> next ; 
        } 
        second -> next = NULL ;
        first -> next = second_dummy -> next ; 
        return first_dummy -> next ; 
    }
};