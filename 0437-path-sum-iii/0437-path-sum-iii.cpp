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
    void main_function ( TreeNode* root , vector <int> &ans , long long &count , int targetSum ) { 
        if ( root == NULL ) { 
            return ; 
        }
        ans.push_back(root->val) ;  
        long long sum = 0 ; 
        for ( int i = 0 ; i < ans.size() ; i++ ) { 
            sum = sum + ans[i] ; 
        }
        if ( sum == targetSum ) { 
            count++ ; 
        }
        main_function(root->left,ans,count,targetSum) ; 
        main_function(root->right,ans,count,targetSum) ; 
        ans.pop_back() ; 
    }
    void Helper_Function ( TreeNode* root , long long &count , vector <int> &ans , int targetSum ) { 
        if ( root == NULL ) { 
            return ; 
        }
        main_function(root,ans,count,targetSum) ; 
        Helper_Function(root->left,count,ans,targetSum) ; 
        Helper_Function(root->right,count,ans,targetSum) ; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long count = 0 ; 
        vector<int> ans ; 
        Helper_Function(root,count,ans,targetSum) ; 
        return count ; 
    }
};