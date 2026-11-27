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
    void Helper_Function ( TreeNode* root , vector <int> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_Function(root->left,answer) ; 
        answer.push_back(root->val) ; 
        Helper_Function(root->right,answer) ; 
    }
    bool isValidBST(TreeNode* root) {
        vector <int> answer ; 
        Helper_Function(root,answer) ; 
        int prev = answer[0] ; 
        for ( int i = 1 ; i < answer.size() ; i++ ) { 
            if ( answer[i] <= prev) { 
                return false ; 
            }
            prev = answer[i] ; 
        }
        return true ; 
    }
};