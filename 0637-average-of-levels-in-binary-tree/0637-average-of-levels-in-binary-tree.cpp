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
    void Helper_function ( TreeNode* root , double &sum , int &count , vector <double> &answer ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                sum = sum + curr->val ; 
                count++ ; 
            }
            if ( curr == NULL && q.size() != 0 ) { 
                double avg = sum / count ; 
                count = 0 ; 
                sum = 0 ; 
                answer.push_back(avg) ; 
                q.push(NULL) ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                double avg = sum / count ; 
                count = 0 ; 
                sum = 0 ; 
                answer.push_back(avg) ; 
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
    vector<double> averageOfLevels(TreeNode* root) {
        double sum = 0 ; 
        int count = 0 ;  
        vector <double> answer ; 
        Helper_function(root,sum,count,answer) ; 
        return answer ; 
    }
};