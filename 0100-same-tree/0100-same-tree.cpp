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
    bool Helper_function( TreeNode* p , TreeNode* q ) { 
        queue <TreeNode*> q1 ; 
        queue <TreeNode*> q2 ; 
        if ( p->val != q->val ) { 
            return false ; 
        }
        q1.push(p) ; 
        q2.push(q) ; 
        while ( q1.size() > 0 && q2.size() > 0 ) { 
            TreeNode* curr1 = q1.front() ; 
            TreeNode* curr2 = q2.front() ; 
            q1.pop() ; 
            q2.pop() ; 
            if ( curr1->val != curr2->val ) { 
                return false ; 
            }
            if ( curr1->left != NULL && curr2->left != NULL ) { 
                q1.push(curr1->left) ; 
                q2.push(curr2->left) ; 
            }
            else if ( curr1->left != NULL || curr2->left != NULL ) { 
                return false ; 
            }
            if ( curr1->right != NULL && curr2->right != NULL ) { 
                q1.push(curr1->right) ; 
                q2.push(curr2->right) ; 
            }
            else if ( curr1->right != NULL || curr2->right != NULL ) { 
                return false ; 
            }
        }
        if ( q1.size() == 0 && q2.size() == 0 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) { 
        if ( p == NULL && q == NULL ) { 
            return true ; 
        }
        else if ( p == NULL || q == NULL ) { 
            return false ; 
        }
        return Helper_function(p,q) ; 
    }
};