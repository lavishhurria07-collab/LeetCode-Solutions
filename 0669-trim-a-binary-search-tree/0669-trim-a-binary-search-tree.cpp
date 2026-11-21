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
    TreeNode* main_function ( TreeNode* root , int low , int high ) { 
        if ( root == NULL ) { 
            return NULL ; 
        }
        if ( root->val < low ) { 
            return main_function(root->right,low,high) ; 
        }
        if ( root->val > high ) { 
            return main_function(root->left,low,high) ; 
        }
        root->left = main_function(root->left,low,high) ; 
        root->right = main_function(root->right,low,high) ; 
        return root ; 
    }
    void min_val ( TreeNode* &root , int &value , TreeNode* &node ) { 
        if ( root == NULL ) { 
            return ; 
        }
        min_val(root->left,value,node) ; 
        if ( value > root->val ) { 
            node = root ; 
            value = root->val ; 
        }
        min_val(root->right,value,node) ; 
    }
    void Helper_Function ( TreeNode* &root , int &v ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val > v ) { 
            Helper_Function(root->left,v) ; 
        } 
        if ( root->val < v ) { 
            Helper_Function(root->right,v) ; 
        } 
        if ( root->val == v ) { 
            if ( root->left == NULL && root ->right == NULL ) { 
                delete root ; 
                root = NULL ; 
                return ; 
            }
            if ( root->left == NULL && root->right != NULL ) { 
                TreeNode* temp = root ; 
                root = root->right ; 
                delete temp ; 
                return ; 
            }
            if ( root->left != NULL && root->right == NULL ) { 
                TreeNode* temp = root ; 
                root = root->left ; 
                delete temp ; 
                return ; 
            }
            if ( root->left != NULL && root->right != NULL ) { 
                TreeNode* node = root->right ; 
                int value = root->right->val ; 
                min_val(root->right,value,node) ; 
                root->val = node->val ; 
                Helper_Function(root->right,value) ; 
            }
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) { 
        return main_function(root,low,high);
    }
};