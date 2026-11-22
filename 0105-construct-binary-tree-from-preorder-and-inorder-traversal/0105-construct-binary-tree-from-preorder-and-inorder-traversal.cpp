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
    TreeNode* Helper_Function ( vector <int> &preorder , vector <int> &inorder , int &index , int start , int end ) { 
        if ( start > end ) { 
            return NULL ; 
        }
        int value = preorder[index] ; 
        TreeNode* root = new TreeNode(value) ; 
        int boundary = -1 ; 
        for ( int i = start ; i <= end ; i++ ) { 
            if ( inorder[i] == value ) { 
                boundary = i ; 
                break ; 
            }
        } 
        index++ ; 
        root->left = Helper_Function(preorder,inorder,index,start,boundary-1) ; 
        root->right = Helper_Function(preorder,inorder,index,boundary+1,end) ; 
        return root ; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0 ; 
        int start = 0 ; 
        int end = preorder.size() - 1 ; 
        TreeNode* root = Helper_Function(preorder,inorder,index,start,end) ; 
        return root ; 
    }
};