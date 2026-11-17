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
    void Helper_function ( TreeNode* root , int val , TreeNode* &curr ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val == val ) { 
            curr = root ; 
            return ; 
        }
        if ( root->val > val ) { 
            Helper_function(root->left,val,curr) ; 
        }
        if ( root->val < val ) { 
            Helper_function(root->right,val,curr) ; 
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = NULL ; 
        Helper_function(root,val,curr) ; 
        return curr ; 
    }
};