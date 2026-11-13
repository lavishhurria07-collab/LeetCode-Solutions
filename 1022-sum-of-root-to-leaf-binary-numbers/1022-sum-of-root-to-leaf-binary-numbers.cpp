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
    int sumRootToLeaf(TreeNode* root) {
        vector <int> ans ; 
        vector<vector<int>> answer ; 
        helper_function(root,ans,answer) ; 
        int sum = 0 ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            int number = 0 ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                number = number * 2 + answer[i][j] ; 
            }
            sum = sum + number ; 
        }
        return sum ; 
    }
};