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
    void Helper_function ( TreeNode* root , vector <int> &answer , vector <int> &temp ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode *curr = q.front() ; 
            q.pop() ;
            if ( curr != NULL ) { 
                temp.push_back(curr->val) ; 
            } 
            if ( curr == NULL && q.size() != 0 ) { 
                q.push(NULL) ; 
                int a = temp.back() ; 
                answer.push_back(a) ; 
                temp.clear() ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                int a = temp.back() ; 
                answer.push_back(a) ; 
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
    vector<int> rightSideView(TreeNode* root) { 
        if ( root == NULL ) { 
            return {} ; 
        }
        vector <int> answer ; 
        vector <int> temp ; 
        Helper_function(root,answer,temp) ; 
        return answer ; 
    }
};