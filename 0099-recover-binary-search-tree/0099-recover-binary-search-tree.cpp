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
    void Helper_Function ( TreeNode* root , vector <TreeNode*> &inorder ) { 
        if ( root == NULL ) { 
            return ; 
        }
        Helper_Function(root->left,inorder) ; 
        inorder.push_back(root) ; 
        Helper_Function(root->right,inorder) ; 
    }
    void recoverTree(TreeNode* root) {
        vector <TreeNode*> answer ; 
        Helper_Function(root,answer) ; 
        vector <TreeNode*> temp = answer ; 
        sort(temp.begin(),temp.end(),[](TreeNode* a , TreeNode* b ) { return a->val < b->val ; } ) ; 
        TreeNode* node1 = NULL ; 
        TreeNode* node2 = NULL ; 
        int index = 0 ; 
        for ( int i = 0 ; i < answer.size() ; i++ ) { 
            if ( answer[i] != temp[i] ) { 
                node1 = answer[i] ; 
                index = i ; 
                break ; 
            }
        }
        for ( int j = index + 1 ; j < answer.size() ; j++ ) { 
            if ( answer[j] != temp[j] ) { 
                node2 = answer[j] ; 
                break ; 
            }
        }
        int val1 = node1->val ; 
        node1->val = node2->val ; 
        node2->val = val1 ; 
    }
};