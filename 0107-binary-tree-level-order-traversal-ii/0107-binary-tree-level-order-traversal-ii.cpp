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
    void Helper_Function ( TreeNode* root , vector <int> &level , vector<vector<int>> &answer ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                level.push_back(curr->val) ; 
            }
            if ( curr == NULL && q.size() != 0 ) { 
                answer.push_back(level) ; 
                level.clear() ; 
                q.push(NULL) ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                answer.push_back(level) ; 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) { 
        if ( root == NULL ) { 
            return {} ; 
        }
        vector <int> level ; 
        vector<vector<int>> answer ; 
        Helper_Function(root,level,answer) ; 
        reverse(answer.begin(),answer.end()) ; 
        return answer ; 
    }
};