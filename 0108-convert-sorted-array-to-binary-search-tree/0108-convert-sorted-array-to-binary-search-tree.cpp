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
    TreeNode* Helper_Function( vector<int> &nums , int left , int right ) { 
        if ( left > right ) { 
            return NULL ; 
        }
        int middle = left + ( right - left ) / 2 ; 
        TreeNode* root = new TreeNode() ; 
        root->val = nums[middle] ; 
        root->left = Helper_Function(nums,left,middle-1) ; 
        root->right = Helper_Function(nums,middle+1,right) ; 
        return root ; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        int left = 0 ; 
        int right = nums.size() - 1 ;  
        TreeNode* root = Helper_Function(nums,left,right) ; 
        return root ; 
    }
};