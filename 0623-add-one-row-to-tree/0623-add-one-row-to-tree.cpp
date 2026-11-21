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
    void Helper_Function(TreeNode* root , int val , int depth , int &level , queue <TreeNode*> &elements , vector<TreeNode*> &nodes ) { 
        elements.push(root) ; 
        elements.push(NULL) ; 
        while ( elements.size() > 0 ) { 
            TreeNode* curr = elements.front() ; 
            elements.pop() ; 
            if ( curr != NULL ) { 
                nodes.push_back(curr) ; 
            }
            if ( curr == NULL ) { 
                if ( level == depth - 1 ) { 
                    return ; 
                }
                if ( elements.empty() ) { 
                    return ; 
                }
                level++ ; 
                elements.push(NULL) ; 
                nodes.clear() ; 
                continue ; 
            }
            if ( curr->left != NULL ) { 
                elements.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                elements.push(curr->right) ; 
            }
        }
    }
    void main_function ( int val , vector<TreeNode*> &nodes ) { 
        for ( int i = 0 ; i < nodes.size() ; i++ ) { 
            TreeNode* lefttree = nodes[i]->left ; 
            TreeNode* righttree = nodes[i]->right ; 
            TreeNode* newnode1 = new TreeNode(val) ; 
            TreeNode* newnode2 = new TreeNode(val) ;
            newnode1->left = lefttree ; 
            newnode2->right = righttree ; 
            nodes[i]->left = newnode1 ; 
            nodes[i]->right = newnode2 ; 
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if ( depth == 1 ) { 
            TreeNode* newnode = new TreeNode(val) ; 
            newnode->left = root ; 
            root = newnode ; 
            return root ; 
        }
        else { 
            int level = 1 ;  
            queue <TreeNode*> elements ;  
            vector<TreeNode*> nodes ; 
            Helper_Function(root,val,depth,level,elements,nodes) ; 
            main_function(val,nodes) ; 
            return root ; 
        }
    }
};