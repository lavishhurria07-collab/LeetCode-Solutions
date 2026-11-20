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
    bool isValidBST(TreeNode* root) { 
        vector <int> ans ; 
        Helper_Function(root,ans) ; 
        int prev = ans[0] ; 
        for ( int i = 1 ; i < ans.size() ; i++ ) { 
            if ( ans[i] <= prev ) { 
                return false ; 
            }
            prev = ans[i] ; 
        }
        return true ; 
    }
};