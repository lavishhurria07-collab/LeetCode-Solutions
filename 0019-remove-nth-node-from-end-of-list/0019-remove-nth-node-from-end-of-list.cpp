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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head ; 
        int count = 0 ; 
        while ( temp != NULL ) { 
            count++ ; 
            temp = temp -> next ; 
        }
        temp = head ; 
        if ( count == 1 && n == 1 ) { 
            delete head ; 
            return NULL ; 
        }
        else if ( count == n ) { 
            head = head -> next ; 
            return head ; 
        }
        else { 
            int pos = count - n ; 
            for ( int i = 0 ; i < pos - 1 ; i++ ) { 
                temp = temp -> next ; 
            }
            temp -> next = temp->next->next ; 
            return head ;
        }
    }
};