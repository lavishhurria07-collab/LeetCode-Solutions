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
    void TreeTraversal ( TreeNode* root , vector <int> &answer ) { 
        if ( root == NULL ) { 
            return ; 
        }
        TreeTraversal(root->left,answer) ; 
        if ( root->left == NULL && root->right == NULL ) { 
            answer.push_back(root->val) ; 
        }
        TreeTraversal(root->right,answer) ; 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> answer1 ; 
        vector <int> answer2 ; 
        TreeTraversal(root1,answer1) ; 
        TreeTraversal(root2,answer2) ; 
        if ( answer1.size() != answer2.size() ) { 
            return false ; 
        }
        for ( int i = 0 ; i < answer1.size() ; i++ ) { 
            if ( answer1[i] != answer2[i] ) { 
                return false ; 
            }
        }
        return true ; 
    }
};