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
        if ( head->next == NULL ) { 
            return head ; 
        }
        ListNode* dummy = new ListNode(0) ; 
        dummy->next = head ; 
        ListNode* start = NULL ; 
        ListNode* prev = NULL ; 
        if ( left == 1 ) { 
            start = head ; 
            prev = dummy ; 
        }
        else { 
            ListNode* temp = head ; 
            for ( int i = 1 ; i < left - 1 ; i++ ) { 
                temp = temp->next ; 
            }
            prev = temp ; 
            start = temp->next ; 
        } 
        ListNode* prev_head = prev ; 
        ListNode* start_head = start ; 
        ListNode* end = NULL ; 
        ListNode* temp = head ; 
        for ( int i = 0 ; i < right - 1 ; i++ ) { 
            temp = temp->next ; 
        }
        end = temp->next ; 
        temp = start ; 
        while ( temp != end ) { 
            ListNode* nxt = temp->next ; 
            temp->next = prev ; 
            prev = temp ; 
            temp = nxt ; 
        }
        prev_head->next = prev ; 
        start_head->next = end ; 
        dummy = dummy->next ; 
        return dummy ; 
    }
};