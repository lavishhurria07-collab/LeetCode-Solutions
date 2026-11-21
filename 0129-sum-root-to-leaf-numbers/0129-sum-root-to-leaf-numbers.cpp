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
    void Helper_Function ( TreeNode* root , vector<int> &level , int &sum ) { 
        if ( root == NULL ) { 
            return ; 
        }
        level.push_back(root->val) ; 
        Helper_Function(root->left,level,sum) ; 
        Helper_Function(root->right,level,sum) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            int a = 0 ; 
            for ( int i = 0 ; i < level.size() ; i++ ) { 
                a = a * 10 + level[i] ; 
            }
            sum = sum + a ; 
        }
        level.pop_back() ; 
    }
    int sumNumbers(TreeNode* root) { 
        vector <int> level ; 
        int sum = 0 ; 
        Helper_Function(root,level,sum) ; 
        return sum ; 
    }
};