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
    void tree_traversal ( TreeNode* target , unordered_map <TreeNode*,TreeNode*> &parent , vector <int> &answer , int k ) { 
        queue <TreeNode*> q ; 
        unordered_set <TreeNode*> visited ; 
        q.push(target) ; 
        visited.insert(target) ; 
        int level = 0 ; 
        while ( q.size() > 0 && level < k ) { 
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
            level++ ; 
        }
        while ( q.size() > 0 ) { 
            TreeNode* a = q.front() ; 
            int value = a->val ; 
            q.pop() ; 
            answer.push_back(value) ; 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*,TreeNode*> parent ; 
        helper_function ( root , parent ) ; 
        vector <int> answer ; 
        tree_traversal ( target , parent , answer , k ) ;  
        return answer ; 
    }
};