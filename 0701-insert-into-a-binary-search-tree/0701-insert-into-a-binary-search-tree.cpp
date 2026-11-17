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
    void Helper_Function ( TreeNode* root , int val ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val > val ) { 
            if ( root->left == NULL ) { 
                TreeNode* curr = new TreeNode(val) ; 
                root->left = curr ; 
                return ; 
            }
            else { 
                Helper_Function(root->left,val) ; 
            }
        }
        if ( root->val < val ) { 
            if ( root->right == NULL ) { 
                TreeNode* curr = new TreeNode(val) ; 
                root->right = curr ; 
                return ; 
            }
            else { 
                Helper_Function(root->right,val) ; 
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) { 
        if ( root == NULL ) { 
            TreeNode* newnode = new TreeNode(val) ; 
            return newnode ; 
        }
        Helper_Function(root,val) ; 
        return root ; 
    }
};