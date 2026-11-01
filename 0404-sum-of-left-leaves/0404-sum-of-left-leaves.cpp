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
    void HelperFunction ( TreeNode* root , int &sum ) { 
        if ( root == NULL ) { 
            sum = 0 ; 
            return ; 
        }
        queue<TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode *curr = q.front() ; 
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                q.push(NULL) ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                break ; 
            }
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
                if ( curr->left->left == NULL && curr->left->right == NULL ) { 
                    sum = sum + curr->left->val ; 
                }
            }
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0 ; 
        HelperFunction(root,sum) ; 
        return sum ; 
    }
};