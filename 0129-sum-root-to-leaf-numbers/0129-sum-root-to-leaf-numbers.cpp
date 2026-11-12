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
    void sum_numbers ( TreeNode* root , vector <int> &temp , vector<vector<int>> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        temp.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            answer.push_back(temp) ; 
        }
        sum_numbers(root->left,temp,answer) ; 
        sum_numbers(root->right,temp,answer) ; 
        temp.pop_back() ; 
    }
    int sumNumbers(TreeNode* root) {
        vector <int> temp ; 
        vector<vector<int>> answer ; 
        sum_numbers(root,temp,answer) ; 
        int sum = 0 ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            int number = 0 ; 
            for ( int j = 0 ; j < answer[i].size() ; j++ ) { 
                number = number * 10 + answer[i][j] ; 
            }
            sum = sum + number ; 
        }
        return sum ; 
    }
};