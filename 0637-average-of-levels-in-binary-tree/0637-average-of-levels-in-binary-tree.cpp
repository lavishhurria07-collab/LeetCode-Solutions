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
    void HelperFunction ( TreeNode* root , vector<double> &ans , double sum , int count )  {
        queue<TreeNode*> q ;
        if ( root == NULL ) { 
            ans.push_back(0.00000) ; 
            return ; 
        } 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                double avg = sum / count ;
                ans.push_back(avg) ; 
                q.push(NULL) ; 
                sum = 0 ; 
                count = 0 ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                double avg = sum / count ;
                ans.push_back(avg) ; 
                break ; 
            }
            sum = sum + curr->val ; 
            count++ ; 
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            } 
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            } 
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        double sum = 0 ; 
        vector<double> ans ; 
        int count = 0 ; 
        HelperFunction(root,ans,sum,count) ; 
        return ans ; 
    }
};