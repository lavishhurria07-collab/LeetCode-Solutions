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
    void main_function ( TreeNode* root , vector <int> &ans , int &index ) { 
        if ( index == ans.size() ) { 
            return ; 
        }
        int value = ans[index] ; 
        TreeNode* newnode = new TreeNode(value) ; 
        root->right = newnode ; 
        index++ ; 
        main_function(root->right,ans,index) ; 
    }
    TreeNode* increasingBST(TreeNode* root) {     
        vector <int> ans ; 
        Helper_Function(root,ans) ; 
        int value = ans[0] ; 
        TreeNode* newnode = new TreeNode(value) ;
        root = newnode ; 
        int index = 1 ; 
        main_function(root,ans,index) ; 
        return root ; 
    }
};