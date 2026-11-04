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
    void Helper_function( TreeNode* root , long long sum , int &count ,int &target ) { 
        if ( root == NULL ) { 
            return ; 
        }
        // if ( root->left == NULL && root->right == NULL ) { 
        //     answer.push_back(ans) ; 
        // }
        sum = sum + root->val ; 
        if ( sum == target ) { 
            count++ ; 
        } 
        Helper_function(root->left,sum,count,target) ; 
        Helper_function(root->right,sum,count,target) ; 
        sum = sum - root->val ; 
    }
    void Traverse ( TreeNode* root , long long sum , int &count ,int &target ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Traverse(root->left,sum,count,target) ; 
        Helper_function(root,sum,count,target) ; 
        Traverse(root->right,sum,count,target) ; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        int target = targetSum ; 
        int count = 0 ; 
        long long sum = 0 ; 
        Traverse(root,sum,count,target) ; 
        // for ( int i = 0 ; i < answer.size() ; i++ ) { 
        //     int sum = 0 ; 
        //     for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
        //         sum = sum + answer[i][j] ; 
        //     }
        //     if ( sum == targetSum ) { 
        //         count++ ; 
        //     }
        // }
        return count ; 
    }
};