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
    void Helper_function( TreeNode* root , vector<int> &ans ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_function(root->left,ans) ; 
        ans.push_back(root->val) ; 
        Helper_function(root->right,ans) ; 
    }
    vector<int> inorderTraversal(TreeNode* root) { 
        vector<int> ans ; 
        Helper_function(root,ans) ; 
        return ans ; 
    } 
};