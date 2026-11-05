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
    void max_depth ( TreeNode* root , int &count ) { 
        queue <TreeNode*> q1 ; 
        q1.push(root) ; 
        q1.push(NULL) ; 
        while ( q1.size() > 0 ) { 
            TreeNode* curr = q1.front() ; 
            q1.pop() ; 
            if ( curr == NULL && q1.size() != 0 ) { 
                q1.push(NULL) ; 
                count++ ; 
                continue ; 
            }
            else if ( curr == NULL && q1.size() == 0 ) { 
                break ; 
            }
            if ( curr->left != NULL ) { 
                q1.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q1.push(curr->right) ; 
            }
        }
    }
    int maxDepth(TreeNode* root) { 
        if ( root == NULL ) { 
            return 0 ; 
        }
        int count = 1 ; 
        max_depth(root,count) ; 
        return count ; 
    }
};