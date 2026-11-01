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
    TreeNode* HelperFunction ( TreeNode* root ) {
        if ( root == NULL ) { 
            return NULL ; 
        }
        swap(root->right,root->left) ; 
        HelperFunction(root->right) ; 
        HelperFunction(root->left) ; 
        return root ; 
    }
    TreeNode* invertTree(TreeNode* root) {
        HelperFunction(root) ; 
        return root ; 
    }
};