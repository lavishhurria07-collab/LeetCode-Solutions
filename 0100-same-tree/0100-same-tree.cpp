/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Helper_function ( TreeNode *p , TreeNode *q ) { 
        if ( p == NULL && q == NULL ) { 
            return true ; 
        }
        if ( p == NULL || q == NULL ) { 
            return false ; 
        }
        queue <TreeNode*> ans1 ; 
        queue <TreeNode*> ans2 ; 
        ans1.push(p) ; 
        ans2.push(q) ; 
        while ( ans1.size() > 0 && ans2.size() > 0 ) { 
            TreeNode *curr1 = ans1.front() ; 
            TreeNode *curr2 = ans2.front() ; 
            if ( curr1->val != curr2->val ) { 
                return false ; 
            }
            ans1.pop() ; 
            ans2.pop() ; 
            if ( curr1->left != NULL && curr2->left != NULL ) { 
                ans1.push(curr1->left) ; 
                ans2.push(curr2->left) ; 
            }
            else if ( curr1->left != NULL || curr2->left != NULL ) { 
                return false ; 
            }
            if ( curr1->right != NULL && curr2->right != NULL ) { 
                ans1.push(curr1->right) ; 
                ans2.push(curr2->right) ; 
            }
            else if ( curr1->right != NULL || curr2->right != NULL ) { 
                return false ; 
            }
        }
        if ( ans1.size() == 0 && ans2.size() == 0 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = Helper_function(p,q) ; 
        return result ; 
    }
};