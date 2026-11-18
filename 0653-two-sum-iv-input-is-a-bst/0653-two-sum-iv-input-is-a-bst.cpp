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
    void Helper_function ( TreeNode* root , vector <int> &ans ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_function(root->left,ans) ; 
        ans.push_back(root->val) ;
        Helper_function(root->right,ans) ; 
    }
    bool findTarget(TreeNode* root, int k) { 
        vector <int> ans ; 
        Helper_function(root,ans) ; 
        int left = 0 ; 
        int right = ans.size() - 1 ; 
        while ( left < right ) { 
            if ( ans[left] + ans[right] == k ) { 
                return true ; 
            }
            else if ( ans[left] + ans[right] < k ) { 
                left++ ; 
            }
            else if ( ans[left] + ans[right] > k ) { 
                right-- ; 
            }
        }
        return false ; 
    }
};