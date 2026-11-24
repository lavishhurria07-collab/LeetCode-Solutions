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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0 ; 
        ListNode* temp = head ; 
        while ( temp != NULL ) { 
            size++ ; 
            temp = temp->next ; 
        }
        ListNode* first = head ; 
        for ( int i = 0 ; i < k - 1 ; i++ ) { 
            first = first->next ; 
        }
        ListNode* second = head ; 
        for ( int i = 0 ; i < size - k ; i++ ) { 
            second = second->next ; 
        }
        swap(first->val,second->val) ; 
        return head ; 
    }
};