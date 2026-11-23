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
    void Helper_Function( TreeNode* root , int &count ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                count++ ; 
                q.push(NULL) ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                count++ ; 
                return ; 
            }
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    bool main_function ( TreeNode* root ) { 
        if ( root == NULL ) { 
            return true ; 
        }
        int count1 = 0 ; 
        int count2 = 0 ; 
        if ( root->left != NULL ) { 
            Helper_Function(root->left,count1) ; 
        }
        if ( root->right != NULL ) { 
            Helper_Function(root->right,count2) ; 
        }
        if ( abs(count1-count2) != 0 && abs(count1-count2) != 1 ) { 
            return false ; 
        }
        bool first = main_function(root->left) ; 
        bool second = main_function(root->right) ; 
        return first && second ; 
    }
    bool isBalanced(TreeNode* root) {
        if ( root == NULL ) { 
            return true ; 
        }
        return main_function(root) ; 
    }
};