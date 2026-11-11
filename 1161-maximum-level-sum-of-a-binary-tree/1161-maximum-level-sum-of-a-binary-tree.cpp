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
    void Helper_function ( TreeNode* root , int &level , int &sum , int &max_sum , int &max_level ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                sum = sum + curr->val ; 
            } 
            if ( curr == NULL && q.size() != 0 ) { 
                if ( max_sum < sum ) { 
                    max_sum = sum ; 
                    max_level = level ; 
                }
                sum = 0 ; 
                level++ ; 
                q.push(NULL) ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                if ( max_sum < sum ) { 
                    max_sum = sum ; 
                    max_level = level ; 
                }
                return ; 
            } 
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            } 
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int level = 1 ;  
        int sum = 0 ;
        int max_sum = INT_MIN ; 
        int max_level = 1 ; 
        Helper_function(root,level,sum,max_sum,max_level) ; 
        return max_level ; 
    }
};