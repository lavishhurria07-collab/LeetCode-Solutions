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
    void path_p_function ( TreeNode* p , unordered_map <TreeNode*,TreeNode*> &parent , vector <TreeNode*> &pathP ) { 
        TreeNode* curr1 = p ; 
        pathP.push_back(curr1) ; 
        while ( curr1 != NULL && parent.find(curr1) != parent.end() ) { 
            curr1 = parent[curr1] ; 
            pathP.push_back(curr1) ; 
        }
    } 
    void path_q_function ( TreeNode* q , unordered_map <TreeNode*,TreeNode*> &parent , vector<TreeNode*> &pathQ ) { 
        TreeNode* curr2 = q ; 
        pathQ.push_back(curr2) ; 
        while ( curr2 != NULL && parent.find(curr2) != parent.end() ) { 
            curr2 = parent[curr2] ; 
            pathQ.push_back(curr2) ; 
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map <TreeNode*,TreeNode*> parent ; 
        helper_function(root,parent) ; 
        vector <TreeNode*> pathP ; 
        path_p_function (p,parent,pathP) ; 
        vector <TreeNode*> pathQ ; 
        path_q_function (q,parent,pathQ) ; 
        int p1 = pathP.size() - 1 ; 
        int q1 = pathQ.size() - 1 ; 
        TreeNode* lca = NULL ; 
        while ( p1 >= 0 && q1 >= 0 ) { 
            if ( pathP[p1] == pathQ[q1] ) { 
                lca = pathP[p1] ; 
                p1-- ; 
                q1-- ; 
            }
            else { 
                return lca ; 
            }
        }
        return lca ; 
    }
};