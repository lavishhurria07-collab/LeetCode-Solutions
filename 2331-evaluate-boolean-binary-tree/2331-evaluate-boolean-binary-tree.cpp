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
    bool Helper_Function ( TreeNode* root ) { 
        if ( root == NULL ) { 
            return false ; 
        }
        if ( root->left == NULL && root->right == NULL ) { 
            return root->val ; 
        }
        if ( root->val == 2 ) { 
            return Helper_Function(root->left)||Helper_Function(root->right) ; 
        }
        if ( root->val == 3 ) { 
            return Helper_Function(root->left) && Helper_Function(root->right) ; 
        }
        return false ; 
    }
    bool evaluateTree(TreeNode* root) {
        return Helper_Function(root) ; 
    }
};