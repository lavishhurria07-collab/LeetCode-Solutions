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
    bool isPalindrome(ListNode* head) {
        int count = 0 ;
        ListNode *temp = head ; 
        while ( temp != NULL ) { 
            count++ ; 
            temp = temp -> next ; 
        }
        int middle = count / 2 ; 
        temp = head ; 
        ListNode *prev = NULL ; 
        ListNode *nxt = NULL ; 
        ListNode *current ; 
        for ( int i = 0 ; i < middle ; i++ ) { 
            temp = temp -> next ; 
        }
        current = temp ; 
        while ( current != NULL ) { 
            nxt = current -> next ; 
            current -> next = prev ; 
            prev = current ; 
            current = nxt ; 
        }
        current = prev ;  
        ListNode *temp1 = head ; 
        while ( current != NULL ) { 
            if ( current -> val != temp1 -> val ) { 
                return false ; 
            }
            current = current -> next ; 
            temp1 = temp1 -> next ; 
        }
        return true ; 
    }
};