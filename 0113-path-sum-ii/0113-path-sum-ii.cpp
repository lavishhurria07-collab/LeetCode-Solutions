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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum ) { 
        vector <int> ans ; 
        vector<vector<int>> answer ; 
        Helper_function(root,ans,answer) ; 
        vector<vector<int>> result ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            int sum = 0 ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                sum = sum + answer[i][j] ; 
            }
            if ( sum == targetSum ) { 
                result.push_back(answer[i]) ; 
            }
        }
        return result ; 
    }
};