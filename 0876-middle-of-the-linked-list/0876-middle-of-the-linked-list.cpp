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
    ListNode* middleNode(ListNode* head) {
        // ListNode *temp = head ; 
        // int count = 0 ; 
        // while ( temp != NULL ) { 
        //     temp = temp -> next ; 
        //     count++ ; 
        // }
        // if ( count == 1 ) { 
        //     return head ; 
        // }
        // temp = head ; 
        // for ( int i = 0 ; i < ( count / 2 - 1 ) ; i++ ) { 
        //     temp = temp -> next ; 
        // }
        // return temp -> next ; 
        // SLOW AND FAST POINTER APPROACH . 
        ListNode *fast = head ;
        ListNode *slow = head ;  
        while ( fast != NULL && fast -> next != NULL ) { 
            fast = fast->next->next ; 
            slow = slow -> next ; 
        } 
        return slow ; 
    }
};