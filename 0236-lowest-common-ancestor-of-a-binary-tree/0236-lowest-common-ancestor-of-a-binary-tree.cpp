/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    void helper_function ( TreeNode* root , unordered_map <TreeNode*,TreeNode*> &parent ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->left != NULL ) { 
            parent[root->left] = root ; 
            helper_function(root->left,parent) ; 
        }
        if ( root->right != NULL ) { 
            parent[root->right] = root ; 
            helper_function(root->right,parent) ; 
        }
    }
    void path_of_p ( TreeNode* p , unordered_map <TreeNode*,TreeNode*> &parent , vector<TreeNode*> &path_p ) { 
        TreeNode* curr1 = p ; 
        path_p.push_back(curr1) ; 
        while ( curr1 != NULL ) { 
            curr1 = parent[curr1] ; 
            path_p.push_back(curr1) ; 
        }
    }
    void path_of_q ( TreeNode* q , unordered_map <TreeNode*,TreeNode*> &parent , vector<TreeNode*> &path_q ) { 
        TreeNode* curr1 = q ; 
        path_q.push_back(curr1) ; 
        while ( curr1 != NULL ) { 
            curr1 = parent[curr1] ; 
            path_q.push_back(curr1) ; 
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map <TreeNode*,TreeNode*> parent ; 
        helper_function(root,parent) ; 
        vector<TreeNode*> path_p ; 
        path_of_p(p,parent,path_p) ; 
        vector<TreeNode*> path_q ; 
        path_of_q(q,parent,path_q) ; 
        int i = path_p.size() - 1 ; 
        int j = path_q.size() - 1 ; 
        TreeNode* lca = NULL ; 
        while ( i >= 0 && j >= 0 ) { 
            if ( path_p[i] == path_q[j] ) { 
                lca = path_p[i] ; 
                i-- ; 
                j-- ; 
            }
            else { 
                return lca ; 
            }
        } 
        return lca ; 
    }
};