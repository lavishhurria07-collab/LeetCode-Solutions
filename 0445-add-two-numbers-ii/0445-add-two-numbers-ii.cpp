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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        vector <int> number1 ; 
        while ( l1 != NULL ) { 
            number1.push_back(l1->val) ; 
            l1 = l1->next ; 
        }
        vector <int> number2 ; 
        while ( l2 != NULL ) { 
            number2.push_back(l2->val) ; 
            l2 = l2->next ; 
        }
        ListNode* first = new ListNode(0) ; 
        ListNode* head = first ; 
        int carry = 0 ; 
        while ( number1.size() > 0 && number2.size() > 0 ) { 
            int sum = number1.back() + number2.back() + carry ; 
            number1.pop_back() ; 
            number2.pop_back() ; 
            if ( sum > 9 ) { 
                carry = sum / 10 ; 
            }
            else { 
                carry = 0 ; 
            }
            int v = sum % 10 ; 
            ListNode* node = new ListNode(v) ; 
            first->next = node ; 
            first = first->next ;  
        }
        while ( number1.size() > 0 ) { 
            int value = number1.back() + carry ; 
            number1.pop_back() ; 
            ListNode* node = new ListNode(value%10) ; 
            if ( value > 9 ) { 
                carry = value / 10 ; 
            }
            else { 
                carry = 0 ; 
            }
            first->next = node ; 
            first = first->next ; 
        }
        while ( number2.size() > 0 ) { 
            int value = number2.back() + carry ; 
            number2.pop_back() ; 
            ListNode* node = new ListNode(value%10) ; 
            if ( value > 9 ) { 
                carry = value / 10 ; 
            }
            else { 
                carry = 0 ;
            }
            first->next = node ; 
            first = first->next ; 
        } 
        if ( carry != 0 ) { 
            ListNode* n = new ListNode(carry) ; 
            first->next = n ; 
            first = first->next ; 
        }
        head = head->next ; 
        ListNode* prev = NULL ; 
        ListNode* curr = head ; 
        while ( curr != NULL ) { 
            ListNode* nxt = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nxt ; 
        }
        return prev ; 
    }
};