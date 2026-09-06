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
    vector<ListNode*> splitListToParts(ListNode* head, int k) { 
        vector <ListNode*> add ; 
        ListNode *temp = head ; 
        int length = 0 ; 
        while ( temp != NULL ) { 
            length++ ; 
            temp = temp -> next ; 
        }
        temp = head ; 
        ListNode *newptr ; 
        int size = length / k ; 
        int extra  = length % k ; 
        if ( length < k ) { 
            while ( temp != NULL ) { 
                ListNode *newptr = temp -> next ; 
                temp -> next = NULL ; 
                add.push_back(temp) ; 
                temp = newptr ; 
            }
            while ( add.size() < k ) { 
                add.push_back(NULL) ; 
            }
            return add ; 
        }
        while ( temp != NULL ) { 
            ListNode *newptr = temp ; 
            add.push_back(newptr) ; 
            int base ; 
            if ( extra > 0 ) { 
                base = size + 1 ; 
                extra-- ; 
            }
            else { 
                base = size ; 
            }
            for ( int i = 0 ; i < base - 1 ; i++ ) { 
                if ( temp -> next != NULL ) { 
                    temp = temp -> next ; 
                }
            }
            newptr = temp -> next ; 
            temp -> next = NULL ; 
            temp = newptr ; 
        }
        return add ; 
    }
};