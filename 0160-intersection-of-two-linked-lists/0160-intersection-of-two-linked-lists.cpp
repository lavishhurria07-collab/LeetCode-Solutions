/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void Helper_Function ( ListNode* head , unordered_set <ListNode*> &ans ) { 
        ListNode* temp = head ; 
        while ( temp != NULL ) { 
            ans.insert(temp) ; 
            temp = temp->next ; 
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set <ListNode*> nodeA ; 
        Helper_Function(headA,nodeA) ; 
        while ( headB != NULL ) { 
            if ( nodeA.find(headB) != nodeA.end() ) { 
                return headB ; 
            }
            headB = headB->next ; 
        }
        return NULL ; 
    }
};