/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution { 
public: 
    void Helper_Function ( TreeNode* original , TreeNode* cloned , TreeNode* target , TreeNode* &result ) { 
        if ( original == NULL && cloned == NULL ) { 
            return ; 
        }
        if ( original == target ) { 
            result = cloned ; 
            return ; 
        }
        Helper_Function(original->left,cloned->left,target,result) ; 
        Helper_Function(original->right,cloned->right,target,result) ;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result = NULL ; 
        Helper_Function(original,cloned,target,result) ; 
        return result ; 
    }
};