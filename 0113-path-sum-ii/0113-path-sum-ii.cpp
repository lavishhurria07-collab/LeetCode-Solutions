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
    void Helper_Function ( TreeNode* root , vector<int> &answer , vector<vector<int>> &ans , int targetSum ) { 
        if ( root == NULL ) { 
            return ; 
        }
        answer.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            int sum = 0 ; 
            for ( int i = 0 ; i < answer.size() ; i++ ) { 
                sum = sum + answer[i] ; 
            }
            if ( sum == targetSum ) { 
                ans.push_back(answer) ; 
            }
        }
        Helper_Function(root->left,answer,ans,targetSum) ; 
        Helper_Function(root->right,answer,ans,targetSum) ; 
        answer.pop_back() ; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> answer ; 
        vector<vector<int>> ans ; 
        Helper_Function(root,answer,ans,targetSum) ; 
        return ans ; 
    }
};