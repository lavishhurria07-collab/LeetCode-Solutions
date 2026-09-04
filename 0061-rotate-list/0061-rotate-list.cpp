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
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == NULL || head -> next == NULL ) { 
            return head ; 
        }
        int length = 0 ; 
        ListNode *temp = head ; 
        while ( temp != NULL ) { 
            length++ ; 
            temp = temp -> next ; 
        }
        k = k % length ; 
        if ( k == 0 ) { 
            return head ; 
        }
        int i = 0 ; 
        temp = head ; 
        while ( i < k ) { 
            ListNode *link = head ; 
            while ( temp->next->next != NULL ) { 
                temp = temp -> next ; 
            }
            ListNode *last = temp -> next ; 
            temp->next->next = link ; 
            temp -> next = NULL ;  
            head = last ;
            temp = head ; 
            i++ ;  
        }
        return head ; 
    }
};