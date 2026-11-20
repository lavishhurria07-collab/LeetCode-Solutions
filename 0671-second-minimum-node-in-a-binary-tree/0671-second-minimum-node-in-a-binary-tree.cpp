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
    void Helper_Function ( TreeNode* root , vector <int> &ans , int &value ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val > value ) { 
            ans.push_back(root->val) ; 
        }
        Helper_Function(root->left,ans,value) ; 
        Helper_Function(root->right,ans,value) ; 
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector <int> ans ; 
        int value = root->val ; 
        Helper_Function(root,ans,value) ; 
        if ( ans.size() == 0 ) { 
            return -1 ; 
        }
        int minimum = *min_element(ans.begin(),ans.end()) ; 
        return minimum ; 
    }
};