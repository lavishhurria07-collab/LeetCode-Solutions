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
        if ( head->next == NULL && n == 1 ) { 
            return NULL ; 
        }
        int size = 0 ; 
        ListNode* temp = head ; 
        while ( temp != NULL ) { 
            size = size + 1 ; 
            temp = temp->next ; 
        }
        if ( size == n ) { 
            head = head->next ; 
            return head ; 
        }
        ListNode* node = head ; 
        for ( int i = 0 ; i < size - n - 1 ; i++ ) { 
            node = node->next ; 
        } 
        node->next = node->next->next ; 
        return head ; 
    }
};