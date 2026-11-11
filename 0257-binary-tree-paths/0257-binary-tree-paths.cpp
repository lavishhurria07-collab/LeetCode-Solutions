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
    void Helper_function ( TreeNode* root , vector<int> &temp , vector<vector<int>> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        temp.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            answer.push_back(temp) ; 
        }
        Helper_function(root->left,temp,answer) ; 
        Helper_function(root->right,temp,answer) ; 
        temp.pop_back() ; 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp ; 
        vector<vector<int>> answer ; 
        Helper_function(root,temp,answer) ; 
        vector<string> result ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            string a = "" ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                a = a + to_string(answer[i][j]) + "->" ; 
            }
            a.pop_back() ; 
            a.pop_back() ;
            result.push_back(a) ; 
        }
        return result ; 
    }
};