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
    TreeNode* Helper_Function ( vector <int> &nums , int start , int end ) { 
        if ( start > end ) { 
            return NULL ; 
        }
        TreeNode* root = new TreeNode(0) ; 
        int index = start ; 
        int element = nums[start] ; 
        for ( int i = start ; i <= end ; i++ ) { 
            if ( nums[i] > element ) { 
                element = nums[i] ; 
                index = i ; 
            }
        } 
        root->val = element ; 
        root->left = Helper_Function(nums,start,index-1) ; 
        root->right = Helper_Function(nums,index+1,end) ; 
        return root ; 
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start = 0 ; 
        int end = nums.size() - 1 ; 
        TreeNode* root = Helper_Function(nums,start,end) ; 
        return root ; 
    }
};