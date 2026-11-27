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
    void Helper_Function ( TreeNode* root , vector <int> &answer ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                answer.push_back(curr->val) ; 
            } 
            if ( curr == NULL && q.size() == 0 ) { 
                return ; 
            }
            else if ( curr == NULL && q.size() != 0 ) { 
                answer.clear() ; 
                q.push(NULL) ; 
                continue ; 
            }
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        vector <int> answer ; 
        Helper_Function(root,answer) ; 
        int sum = 0 ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            sum = sum + answer[i] ; 
        }
        return sum ; 
    }
};