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
    void helper_function ( TreeNode* root , vector <int> &ans , vector<vector<int>> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        ans.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            answer.push_back(ans) ; 
        }
        helper_function(root->left,ans,answer) ; 
        helper_function(root->right,ans,answer) ; 
        ans.pop_back() ; 
    }
    vector<string> binaryTreePaths(TreeNode* root) { 
        vector <int> ans ; 
        vector<vector<int>> answer ; 
        helper_function(root,ans,answer) ; 
        vector <string> result ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            string c = "" ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                c = c + to_string(answer[i][j]) + "->" ; 
            }
            c.pop_back() ; 
            c.pop_back() ; 
            result.push_back(c) ; 
        } 
        return result ; 
    }
};