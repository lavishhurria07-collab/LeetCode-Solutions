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
    void Helper_function ( TreeNode* root , bool &result , int compare ) { 
        if ( root == NULL ) { 
            result = true ; 
            return ; 
        }
        queue <TreeNode*> Q ; 
        Q.push(root) ; 
        while ( Q.size() > 0 ) { 
            TreeNode* curr = Q.front() ; 
            Q.pop() ; 
            if ( curr->val != compare ) { 
                result = false ; 
                return ; 
            }
            if ( curr->left != NULL ) { 
                Q.push(curr->left) ; 
            } 
            if ( curr->right != NULL ) { 
                Q.push(curr->right) ; 
            }
        }
    }
    bool isUnivalTree(TreeNode* root) {
        int compare = root->val ; 
        bool result = true ; 
        Helper_function(root,result,compare) ; 
        return result ; 
    }
};