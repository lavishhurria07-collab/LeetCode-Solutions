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
    vector<int> findMode(TreeNode* root) {
        vector <int> ans ; 
        Helper_function(root,ans) ; 
        int count = 1 ; 
        int max_freq = 0 ; 
        vector <int> answer ; 
        int prev = ans[0] ; 
        if ( ans.size() == 1 ) { 
            return {ans[0]} ; 
        }
        for ( int i = 1 ; i < ans.size() ; i++ ) { 
            if ( ans[i] == prev ) { 
                count++ ; 
            }
            else if ( ans[i] != prev ) { 
                if ( count > max_freq ) { 
                    answer.clear() ; 
                    answer.push_back(prev) ; 
                    max_freq = count ;
                    count = 1 ;  
                }
                else if ( max_freq == count ) { 
                    answer.push_back(prev) ; 
                    count = 1 ;
                }
                else if ( max_freq > count ) { 
                    count = 1 ; 
                }
                prev = ans[i] ; 
            }
        } 
        if ( count > max_freq ) { 
            answer.clear() ; 
            int a = ans.back() ; 
            answer.push_back(a) ; 
        }
        else if ( count == max_freq ) { 
            int a = ans.back() ; 
            answer.push_back(a) ; 
        }
        return answer ; 
    }
};