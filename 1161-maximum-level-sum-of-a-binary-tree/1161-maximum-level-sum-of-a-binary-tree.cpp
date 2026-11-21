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
    void Helper_Function ( TreeNode* root , vector<int> &level , vector<int> &answer ) { 
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
                int a = 0 ; 
                for ( int i = 0 ; i < level.size() ; i++ ) { 
                    a = a + level[i] ; 
                }
                answer.push_back(a) ; 
                level.clear() ; 
                q.push(NULL) ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                int a = 0 ;  
                for ( int i = 0 ; i < level.size() ; i++ ) { 
                    a = a + level[i] ; 
                } 
                answer.push_back(a) ; 
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
    int maxLevelSum(TreeNode* root) {
        vector <int> level ; 
        vector<int> answer ; 
        Helper_Function(root,level,answer) ; 
        int max_sum = *max_element(answer.begin(),answer.end()) ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            if ( answer[i] == max_sum ) { 
                return ( i + 1 ) ; 
            }
        }
        return 0 ; 
    }
};
