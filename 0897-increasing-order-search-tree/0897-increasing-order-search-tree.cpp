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
    void Helper_Function ( TreeNode* root , vector <int> &ans ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_Function(root->left,ans) ; 
        ans.push_back(root->val) ; 
        Helper_Function(root->right,ans) ; 
    } 
    TreeNode* construct_Tree ( vector <int> &ans , int index ) { 
        if ( index == ans.size() ) { 
            return NULL ; 
        } 
        TreeNode* root = new TreeNode() ; 
        root->val = ans[index] ; 
        root->right = construct_Tree(ans,index+1) ; 
        root->left = NULL ; 
        return root ; 
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector <int> ans ; 
        Helper_Function(root,ans) ; 
        TreeNode* root1 = construct_Tree(ans,0) ; 
        return root1 ; 
    }
};