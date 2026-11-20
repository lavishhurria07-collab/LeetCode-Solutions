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
    void Helper_Function ( TreeNode* root , vector <int> &ans ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_Function(root->left,ans) ; 
        ans.push_back(root->val) ; 
        Helper_Function(root->right,ans) ; 
    }
    vector<int> findMode(TreeNode* root) { 
        vector <int> ans ; 
        Helper_Function(root,ans) ; 
        int curr_element = ans[0] ; 
        int freq = 1 ; 
        int max_freq = 1 ; 
        vector <int> answer ; 
        for ( int i = 1 ; i < ans.size() ; i++ ) { 
            if ( ans[i] == curr_element ) { 
                freq++ ; 
            }
            else if ( ans[i] != curr_element ) {  
                if ( freq > max_freq ) { 
                    answer.clear() ; 
                    answer.push_back(curr_element) ; 
                    max_freq = freq ;
                    curr_element = ans[i] ; 
                    freq = 1 ; 
                }
                else if ( freq < max_freq ) { 
                    freq = 1 ; 
                    curr_element = ans[i] ;
                }
                else if ( freq == max_freq ) { 
                    freq = 1 ; 
                    answer.push_back(curr_element) ; 
                    curr_element = ans[i] ;
                }
            }
        }
        if ( freq > max_freq ) { 
            answer.clear() ; 
            answer.push_back(curr_element) ; 
        }
        else if ( freq == max_freq ) {
            answer.push_back(curr_element) ; 
        }
        return answer ; 
    }
};