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
    vector <int> ans1 ; 
    vector<vector<int>> ans2 ; 
    void TreeTraversal ( TreeNode* root , vector<int> &ans1 , vector<vector<int>> &ans2 ) {  
        if ( root == NULL ) { 
            return ; 
        }
        queue <TreeNode*> Q1 ; 
        Q1.push(root) ; 
        Q1.push(NULL) ; 
        while ( Q1.size() != 0 ) { 
            TreeNode *curr = Q1.front() ; 
            Q1.pop() ; 
            if ( curr != NULL ) { 
                ans1.push_back(curr->val) ; 
            }
            if ( curr == NULL && Q1.size() != 0 ) { 
                ans2.push_back(ans1) ; 
                ans1.clear() ; 
                Q1.push(NULL) ; 
                continue ; 
            }
            if ( curr == NULL && Q1.size() == 0 ) { 
                ans2.push_back(ans1) ;
                ans1.clear() ; 
                break ; 
            }
            if ( curr -> left != NULL ) { 
                Q1.push(curr->left) ; 
            } 
            if ( curr -> right != NULL) { 
                Q1.push(curr->right) ; 
            } 
        }
    } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <int> ans1 ; 
        vector<vector<int>> ans2 ; 
        TreeTraversal(root,ans1,ans2) ; 
        return ans2 ; 
    }
};