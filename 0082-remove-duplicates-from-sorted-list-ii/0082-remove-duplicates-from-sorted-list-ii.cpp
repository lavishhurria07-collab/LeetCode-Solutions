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
    ListNode* deleteDuplicates(ListNode* head) { 
        if ( head == NULL || head->next == NULL ) { 
            return head ; 
        }
        ListNode* temp = head ; 
        unordered_set <int> answer ;
        vector <int> frequency(201,0) ; 
        while ( temp != NULL ) { 
            int value = temp->val ; 
            frequency[value+100]++ ; 
            temp = temp->next ; 
        }
        for ( int i = 0 ; i <= 200 ; i++ ) { 
            if ( frequency[i] > 1 ) { 
                int value = i - 100 ; 
                answer.insert(value) ; 
            }
        }
        ListNode* dummy = new ListNode(0) ; 
        dummy->next = head ; 
        ListNode* prev = dummy ; 
        ListNode* curr = head ; 
        while ( curr != NULL ) { 
            int value = curr->val ; 
            if ( answer.find(value) != answer.end() ) { 
                prev->next = curr->next ; 
                ListNode* del = curr ; 
                curr = curr->next ; 
                delete del ; 
            }
            else { 
                prev = curr ; 
                curr = curr->next ; 
            }
        }
        dummy = dummy->next ; 
        return dummy ; 
    }
};