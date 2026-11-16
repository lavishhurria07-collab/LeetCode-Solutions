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
    void Helper_Function ( TreeNode* root , int val , TreeNode* &curr ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val == val ) { 
            curr = root ; 
            return ; 
        }
        else if ( root->val > val ) { 
            Helper_Function(root->left,val,curr) ; 
        }
        else if ( root->val < val ) { 
            Helper_Function(root->right,val,curr) ; 
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = NULL ; 
        Helper_Function(root,val,curr) ; 
        if ( curr == NULL ) { 
            return NULL ; 
        }
        return curr ; 
    }
};