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
    void Helper_function ( TreeNode* root , vector <int> &ans , vector<vector<int>> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        ans.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            answer.push_back(ans) ; 
        }
        Helper_function(root->left,ans,answer) ; 
        Helper_function(root->right,ans,answer) ; 
        ans.pop_back() ; 
    }
    string smallestFromLeaf(TreeNode* root) {
        vector <int> ans ; 
        vector<vector<int>> answer ; 
        Helper_function(root,ans,answer) ; 
        vector<string> result ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            reverse(answer[i].begin(),answer[i].end()) ; 
        }
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            string s = "" ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                int a = answer[i][j]+97 ; 
                char c = (char)a ; 
                s = s + c ; 
            }
            result.push_back(s) ; 
        } 
        string ch = result[0] ; 
        for ( int i = 1 ; i < result.size() ; i++ ) { 
            if ( ch > result[i] ) { 
                ch = result[i] ; 
            }
        }
        return ch ; 
    }
};