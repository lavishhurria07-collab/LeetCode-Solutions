/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), righ(right{}
 * };
 */
class Solution {
public: 
    bool Helper_function(TreeNode* root1 , TreeNode* root2 ) { 
        queue <TreeNode*> q1 ; 
        queue <TreeNode*> q2 ; 
        q1.push(root1) ; 
        q2.push(root2) ; 
        while( q1.size() > 0 && q2.size() > 0 ) { 
            TreeNode* curr1 = q1.front() ; 
            TreeNode* curr2 = q2.front() ; 
            q1.pop() ; 
            q2.pop() ; 
            if ( curr1 != NULL && curr2 != NULL ) { 
                if ( curr1->left != NULL && curr2->right != NULL ) { 
                    if ( ( curr1->left->val != curr2->right->val ) ) { 
                        return false ; 
                    }
                }
                if ( curr1->right != NULL && curr2->left != NULL ) { 
                    if ( curr1->right->val != curr2->left->val ) { 
                        return false ; 
                    }
                }
            }
            else if (curr1 == NULL && curr2 == NULL) {
                continue;
            }
            else if ( curr1 != NULL || curr2 != NULL ) { 
                return false ; 
            }
            if ( curr1->val != curr2->val ) { 
                return false ; 
            }
            if ( curr1->left!=NULL && curr2->right!=NULL ) { 
                q1.push(curr1->left) ; 
                q2.push(curr2->right) ; 
            }
            else if ( curr1->left!=NULL || curr2->right!=NULL ) { 
                return false ; 
            }
            if ( curr1->right !=NULL && curr2->left !=NULL ) { 
                q1.push(curr1->right) ; 
                q2.push(curr2->left) ; 
            }
            else if ( curr1->right != NULL || curr2->left != NULL ) { 
                return false ; 
            }
        }
        if ( q1.size() == 0 && q2.size() == 0 ) { 
            return true ; 
        }
        else if ( q1.size() == 0 || q2.size() == 0 ) { 
            return false ; 
        }
        return true ; 
    }
    bool isSymmetric(TreeNode* root) {
        if ( root == NULL ) { 
            return true ; 
        }
        else { 
            return Helper_function(root->left, root->right) ;
        }
    }
};