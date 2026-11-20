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
    void Helper_Function ( TreeNode* &root , int key ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val > key ) { 
            Helper_Function(root->left,key) ; 
        } 
        if ( root->val < key ) { 
            Helper_Function(root->right,key) ; 
        } 
        if ( root->val == key ) { 
            if ( root->left == NULL && root->right == NULL ) { 
                root = NULL ; 
                return ; 
            }
            if ( root->left == NULL && root->right != NULL ) { 
                root = root->right ;  
                return ; 
            }
            if ( root->left != NULL && root->right == NULL ) { 
                root = root->left ; 
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        Helper_Function(root,key) ; 
        return root ; 
    }
};