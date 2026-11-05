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
    void Helper_function ( TreeNode* root , vector<int> &ans , vector<vector<int>> &answer ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() != 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ;  
            if ( curr != NULL ) { 
                ans.push_back(curr->val) ;
            }
            if ( curr == NULL && q.size() != 0 ) { 
                answer.push_back(ans) ; 
                q.push(NULL) ; 
                ans.clear() ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                answer.push_back(ans) ; 
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
    vector<vector<int>> levelOrder(TreeNode* root) { 
        if ( root == NULL ) { 
            return {} ; 
        }
        vector<int> ans ; 
        vector<vector<int>> answer ; 
        Helper_function(root,ans,answer) ; 
        return answer ; 
    }
};