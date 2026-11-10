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
    void Helper_function ( TreeNode* root , vector<vector<int>> &answer , vector<int> &ans ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            if ( curr != NULL ) { 
                ans.push_back(curr->val) ; 
            }
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                answer.push_back(ans) ; 
                ans.clear() ; 
                q.push(NULL) ; 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) { 
        if ( root == NULL ) { 
            return {} ; 
        }
        vector<vector<int>> answer ;
        vector<int> ans ; 
        Helper_function(root,answer,ans) ; 
        reverse(answer.begin(),answer.end()) ; 
        return answer ; 
    }
};