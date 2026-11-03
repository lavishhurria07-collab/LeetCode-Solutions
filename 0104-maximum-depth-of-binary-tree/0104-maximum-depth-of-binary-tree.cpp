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
    void Helper_function ( TreeNode* root , int &max_depth ) { 
        if ( root == NULL ) { 
            max_depth = 0 ; 
            return ; 
        }
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ;  
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                max_depth++ ; 
                q.push(NULL) ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                break ; 
            }
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    int maxDepth(TreeNode* root) {
        int max_depth = 1 ; 
        Helper_function(root,max_depth) ; 
        return max_depth ; 
    }
};