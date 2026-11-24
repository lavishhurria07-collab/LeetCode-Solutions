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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if ( head->next == NULL ) { 
            return head ; 
        }
        vector <int> divisors ; 
        ListNode* temp = head ; 
        while ( temp != NULL && temp->next != NULL ) { 
            int first = temp->val ; 
            int second = temp->next->val ; 
            int value = gcd(first,second) ; 
            divisors.push_back(value) ; 
            temp = temp->next ; 
        }
        ListNode* list = head ; 
        int index = 0 ; 
        while ( list != NULL && list->next != NULL && index < divisors.size() ) { 
            ListNode* value = new ListNode(divisors[index]) ; 
            index++ ; 
            ListNode* node = list->next ; 
            value->next = node ; 
            list->next = value ; 
            list = list->next->next ; 
        }
        return head ; 
    }
};