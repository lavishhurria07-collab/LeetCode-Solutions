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
    ListNode* oddEvenList(ListNode* head) {
        if ( head == NULL || head -> next == NULL ) { 
            return head ; 
        } 
        ListNode *odd = head ; 
        ListNode *odd_dummy = odd ; 
        ListNode *even = head -> next ; 
        ListNode *dummy = even ; 
        while ( odd -> next != NULL && even -> next != NULL ) { 
            if ( odd -> next != NULL && odd->next->next != NULL ) {
                odd -> next = odd -> next -> next ; 
            }
            if ( even-> next != NULL ) { 
                even -> next = even -> next -> next ; 
            }
            odd = odd -> next ; 
            even = even -> next ; 
        } 
        odd -> next = dummy ; 
        return odd_dummy ; 
    }
};