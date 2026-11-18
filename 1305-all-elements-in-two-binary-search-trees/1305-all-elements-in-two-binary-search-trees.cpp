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
    void Helper_function ( TreeNode* root , vector <int> &ans ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_function(root->left,ans) ; 
        ans.push_back(root->val) ; 
        Helper_function(root->right,ans) ; 
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) { 
        vector <int> ans1 ; 
        vector <int> ans2 ; 
        Helper_function(root1,ans1) ; 
        Helper_function(root2,ans2) ; 
        vector <int> answer ; 
        int i = 0 ; 
        int j = 0 ; 
        while ( i < ans1.size() && j < ans2.size() ) { 
            if ( ans1[i] > ans2[j] ) { 
                answer.push_back(ans2[j]) ;  
                j++ ; 
            }
            else if ( ans1[i] < ans2[j] ) { 
                answer.push_back(ans1[i]) ; 
                i++ ; 
            }
            else if  ( ans1[i] == ans2[j] ) { 
                answer.push_back(ans2[j]) ; 
                answer.push_back(ans1[i]) ; 
                i++ ; 
                j++ ; 
            }
        }
        while ( i < ans1.size() ) { 
            answer.push_back(ans1[i]) ; 
            i++ ; 
        }
        while ( j < ans2.size() ) { 
            answer.push_back(ans2[j]) ; 
            j++ ; 
        }
        return answer ; 
    }
};