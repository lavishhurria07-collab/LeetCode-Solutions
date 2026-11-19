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
    void Helper_Function(TreeNode* root , int &sum ) { 
        if ( root == NULL ) { 
            return ; 
        }
        sum = sum + root->val ; 
        Helper_Function(root->left,sum) ; 
        Helper_Function(root->right,sum) ; 
    }
    bool checkTree(TreeNode* root) {
        int sum = 0 ; 
        Helper_Function(root,sum) ; 
        int value = root->val ; 
        if ( sum == value * 2 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
};