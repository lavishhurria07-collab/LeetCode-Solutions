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
    void Helper_function ( TreeNode* root ) { 
        queue <TreeNode*> q1 ; 
        q1.push(root) ; 
        while ( q1.size() > 0 ) { 
            TreeNode* curr = q1.front() ; 
            swap(curr->left,curr->right) ; 
            q1.pop() ; 
            if ( curr->left != NULL ) { 
                q1.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q1.push(curr->right) ; 
            }
        }
    }
    TreeNode* invertTree(TreeNode* root) { 
        if ( root == NULL ) { 
            return root ; 
        }
        Helper_function(root) ; 
        return root ; 
    }
};