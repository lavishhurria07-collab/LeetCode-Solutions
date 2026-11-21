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
    void Helper_Function ( TreeNode* root , vector <TreeNode*> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        answer.push_back(root) ; 
        Helper_Function(root->left,answer) ; 
        Helper_Function(root->right,answer) ; 
    }
    void main_function ( TreeNode* root , vector <TreeNode*> &answer , int &index ) { 
        if ( index >= answer.size() ) { 
            return ; 
        }
        root->left = NULL ; 
        root->right = answer[index] ; 
        index++ ; 
        main_function(root->right,answer,index) ; 
    }
    void flatten(TreeNode* root) { 
        vector <TreeNode*> answer ; 
        Helper_Function(root,answer) ; 
        int index = 1 ; 
        main_function(root,answer,index) ; 
    }
};