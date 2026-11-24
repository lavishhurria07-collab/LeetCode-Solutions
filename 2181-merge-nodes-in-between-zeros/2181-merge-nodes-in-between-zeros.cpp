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
    ListNode* mergeNodes(ListNode* head) {
        vector <int> numbers ; 
        head = head->next ; 
        int sum = 0 ; 
        while ( head != NULL ) { 
            if ( head->val == 0 ) { 
                numbers.push_back(sum) ; 
                sum = 0 ; 
            }
            else if ( head->val != 0 ) { 
                sum = sum + head->val ; 
            }
            head = head->next ; 
        }
        int first = numbers[0] ; 
        ListNode* newlist = new ListNode(first) ; 
        ListNode* newhead = newlist ; 
        for ( int i = 1 ; i < numbers.size() ; i++ ) { 
            ListNode* attach = new ListNode(numbers[i]) ; 
            newlist->next = attach ; 
            newlist = newlist->next ; 
        }
        newlist->next = NULL ; 
        return newhead ; 
    }
};