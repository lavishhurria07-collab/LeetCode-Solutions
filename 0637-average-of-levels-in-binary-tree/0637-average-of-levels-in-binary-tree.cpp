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
    void Helper_function ( TreeNode* root , long long &sum , int &count , vector<double> &ans ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                sum = sum + curr->val ; 
                count = count + 1 ; 
            }
            if ( curr == NULL && q.size() == 0 ) { 
                double avg = double ( sum )  / count ; 
                ans.push_back(avg) ; 
                return ; 
            }
            else if ( curr == NULL && q.size() != 0 ) { 
                q.push(NULL) ; 
                double avg = double ( sum ) / count ; 
                ans.push_back(avg) ; 
                sum = 0 ; 
                count = 0 ; 
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans ; 
        int count = 0 ; 
        long long sum = 0 ; 
        Helper_function(root,sum,count,ans) ; 
        return ans ; 
    }
};