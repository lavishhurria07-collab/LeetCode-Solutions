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
    void Helper_function(TreeNode *root,int &count) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                count = count + 1 ; 
                q.push(NULL) ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                break ; 
            } 
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            } 
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    int maxDepth(TreeNode* root) {
        if ( root == NULL ) { 
            return 0 ; 
        }
        int count = 1 ; 
        Helper_function(root,count) ; 
        return count ; 
    }
};