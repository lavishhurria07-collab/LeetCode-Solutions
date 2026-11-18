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
    void sum_function ( TreeNode* root , int &sum ,int val ) { 
        if ( root == NULL ) { 
            return ; 
        }
        sum_function(root->left,sum,val) ;
        if ( root->val >= val ) { 
            sum = sum + root->val ; 
        } 
        sum_function(root->right,sum,val) ; 
    } 
    void Tree_traversal ( TreeNode* root , TreeNode* curr , vector <int> &inorder ) { 
        if ( curr == NULL ) { 
            return ; 
        }
        Tree_traversal(root,curr->left,inorder) ; 
        int sum = 0 ; 
        int val = curr->val ; 
        sum_function(root,sum,val) ; 
        inorder.push_back(sum) ; 
        Tree_traversal(root,curr->right,inorder) ; 
    } 
    void Helper_function ( TreeNode* &root , vector <int> &inorder , int &index ) {
        if ( index == inorder.size() ) { 
            return ; 
        }
        if ( root == NULL ) { 
            return ; 
        }
        Helper_function(root->left,inorder,index) ; 
        int v = inorder[index] ; 
        root->val = v ; 
        index++ ; 
        Helper_function(root->right,inorder,index) ; 
    }
    TreeNode* convertBST(TreeNode* root) { 
        vector <int> inorder ; 
        TreeNode* curr = root ; 
        Tree_traversal(root,curr,inorder) ; 
        int index = 0 ; 
        Helper_function(root,inorder,index) ;
        return root ; 
    }
};