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
    int Helper_function ( TreeNode* root , bool &result ) { 
        if ( root == NULL ) { 
            return 0 ; 
        }
        int left_subtree_height = Helper_function(root->left,result) ; 
        int right_subtree_height = Helper_function(root->right,result) ; 
        int diff = abs(left_subtree_height-right_subtree_height) ; 
        if ( diff > 1 ) { 
            result = false ; 
        }
        return 1 + max(left_subtree_height,right_subtree_height) ; 
    }
    bool isBalanced(TreeNode* root) { 
        if ( root == NULL ) { 
            return true ; 
        }
        bool result = true ; 
        int ans = Helper_function(root,result) ; 
        return result ; 
    }
};