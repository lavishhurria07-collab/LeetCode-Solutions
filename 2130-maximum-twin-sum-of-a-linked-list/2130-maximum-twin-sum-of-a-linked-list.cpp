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
    int pairSum(ListNode* head) {
        vector <int> ans ; 
        while ( head != NULL ) { 
            int value = head->val ; 
            ans.push_back(value) ; 
            head = head->next ; 
        }
        int left = 0 ; 
        int right = ans.size() - 1 ; 
        int max_sum = INT_MIN ; 
        while ( left <= right ) { 
            int sum = ans[left] + ans[right] ; 
            max_sum = max(max_sum,sum) ; 
            left++ ; 
            right-- ; 
        }
        return max_sum ; 
    }
};