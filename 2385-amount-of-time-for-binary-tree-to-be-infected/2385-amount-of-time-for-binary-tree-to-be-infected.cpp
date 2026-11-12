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
    void function ( TreeNode* root , int start , TreeNode* &st ) { 
        if ( root == NULL ) { 
            return ; 
        }
        if ( root->val == start ) { 
            st = root ; 
            return ; 
        }
        function(root->left,start,st) ; 
        function(root->right,start,st) ; 
    }
    void main_function ( TreeNode* &st , unordered_map <TreeNode*,TreeNode*> &parent , int &time ) { 
        queue <TreeNode*> q ; 
        unordered_set <TreeNode*> visited ; 
        q.push(st) ; 
        visited.insert(st) ;  
        while ( q.size() > 0 ) {  
            int size = q.size() ; 
            while ( size > 0 ) { 
                TreeNode* curr = q.front() ; 
                q.pop() ; 
                if ( curr->left != NULL && visited.find(curr->left) == visited.end() ) { 
                    q.push(curr->left) ; 
                    visited.insert(curr->left) ; 
                }
                if ( curr->right != NULL && visited.find(curr->right) == visited.end() ) { 
                    q.push(curr->right) ; 
                    visited.insert(curr->right) ; 
                }
                if ( parent.find(curr) != parent.end() && visited.find(parent[curr]) == visited.end() ) { 
                    q.push(parent[curr]) ; 
                    visited.insert(parent[curr]) ; 
                }
                size-- ; 
            }
            if ( q.size() != 0 ) { 
                time++ ; 
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map <TreeNode*,TreeNode*> parent ; 
        helper_function(root,parent) ; 
        TreeNode* st ; 
        function(root,start,st) ; 
        int time = 0 ; 
        main_function(st,parent,time) ; 
        return time ; 
    }
};