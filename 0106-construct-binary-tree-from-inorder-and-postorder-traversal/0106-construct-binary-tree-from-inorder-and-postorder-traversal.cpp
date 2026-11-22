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
// inorder = left -> root -> right 
// postorder = left -> right -> root 
class Solution { 
public: 
    TreeNode* Helper_Function ( vector <int> &inorder,vector <int> &postorder , int &index , int start , int end ) { 
        if ( start > end ) { 
            return NULL ; 
        }
        int value = postorder[index] ; 
        TreeNode* root = new TreeNode(value) ; 
        int boundary = -1 ; 
        for ( int i = start ; i <= end ; i++ ) { 
            if ( inorder[i] == value ) { 
                boundary = i ; 
                break ; 
            }
        } 
        index-- ; 
        root->right = Helper_Function(inorder,postorder,index,boundary+1,end) ;
        root->left = Helper_Function(inorder,postorder,index,start,boundary-1) ;  
        return root ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size() - 1 ; 
        int start = 0 ; 
        int end = inorder.size() - 1 ; 
        TreeNode* root = Helper_Function(inorder,postorder,index,start,end) ; 
        return root ;  
    }
};