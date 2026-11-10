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
    void Helper_function ( TreeNode* root , vector<vector<int>> &ans , vector<int> &answer ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ;  
            if ( curr != NULL ) { 
                answer.push_back(curr->val) ; 
            }
            q.pop() ;
            if ( curr == NULL && q.size() != 0 ) { 
                ans.push_back(answer) ; 
                q.push(NULL) ; 
                answer.clear() ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                ans.push_back(answer) ; 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if ( root == NULL ) { 
            return {} ; 
        }
        vector<vector<int>> ans ; 
        vector<int> answer ; 
        Helper_function(root,ans,answer) ; 
        return ans ; 
    }
};