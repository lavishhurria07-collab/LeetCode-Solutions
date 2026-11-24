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
    bool isPalindrome(ListNode* head) { 
        if ( head->next == NULL ) { 
            return true ; 
        }
        vector <int> answer ; 
        answer.push_back(head->val) ; 
        ListNode* temp = head->next ;  
        while ( temp != NULL ) { 
            answer.push_back(temp->val) ; 
            temp = temp->next ; 
        } 
        int n = answer.size() ; 
        for ( int i = 0 ; i < n / 2 ; i++ ) { 
            if ( answer[i] != answer[n-i-1] ) { 
                return false ; 
            }
        }
        return true ; 
    }
};