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
    TreeNode* Helper_Function ( TreeNode* root , TreeNode* p , TreeNode* q ) { 
        if ( root == NULL ) { 
            return NULL ; 
        }
        if ( root->val > p->val && root->val > q->val ) { 
            return Helper_Function(root->left,p,q) ; 
        } 
        else if ( root->val < p->val && root->val < q->val ) { 
            return Helper_Function(root->right,p,q) ; 
        }
        else if ( root->val == p->val || root->val == q->val ) { 
            return root ; 
        }
        else { 
            return root ; 
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Helper_Function(root,p,q) ; 
    }
};