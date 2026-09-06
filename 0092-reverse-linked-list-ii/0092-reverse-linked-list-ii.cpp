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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int position = 1 ; 
        ListNode *current = head ; 
        ListNode *prev = NULL ; 
        if ( left == right ) { 
            return head ; 
        }
        while ( position < left ) { 
            prev = current ; 
            current = current -> next ; 
            position++ ; 
        }
        ListNode *leftconn = prev ; 
        ListNode *next = current -> next ; 
        ListNode *rightconn = current ; 
        while ( position <= right  ) {  
            next = current -> next ; 
            current -> next = prev ; 
            prev = current ; 
            current = next ; 
            position++ ; 
        }
        if ( left == 1 ) { 
            rightconn -> next = current ;
            return prev ; 
        }
        leftconn -> next = prev ; 
        rightconn -> next = current ;  
        return head ; 
    }
};