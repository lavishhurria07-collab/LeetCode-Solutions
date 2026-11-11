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
    bool Helper_function ( TreeNode* root , vector <int> &temp , int &level ) { 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            TreeNode* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                temp.push_back(curr->val) ; 
            }
            if ( curr == NULL && q.size() == 0 ) { 
                if ( level % 2 == 0 && temp.size() != 0 ) { 
                    int prev = temp[0] ; 
                    for ( int i = 0 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] % 2 == 0 ) { 
                            return false ; 
                        }
                    }
                    for ( int i = 1 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] > prev ) { 
                            prev = temp[i] ; 
                        }
                        else { 
                            return false ; 
                        }
                    }
                }
                else if ( level % 2 != 0 && temp.size() != 0 ) { 
                    int prev = temp[0] ; 
                    for ( int i = 0 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] % 2 != 0 ) { 
                            return false ; 
                        }
                    }
                    for ( int i = 1 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] < prev ) { 
                            prev = temp[i] ; 
                        }
                        else { 
                            return false ; 
                        }
                    }
                }
                return true ; 
            }
            else if ( curr == NULL && q.size() != 0 ) { 
                q.push(NULL) ; 
                if ( level % 2 == 0 && temp.size() != 0) { 
                    int prev = temp[0] ; 
                    for ( int i = 0 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] % 2 == 0 ) { 
                            return false ; 
                        }
                    }
                    for ( int i = 1 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] > prev ) { 
                            prev = temp[i] ; 
                        }
                        else { 
                            return false ; 
                        }
                    }
                }
                else if ( level % 2 != 0 && temp.size() != 0 ) { 
                    int prev = temp[0] ; 
                    for ( int i = 0 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] % 2 != 0 ) { 
                            return false ; 
                        }
                    }
                    for ( int i = 1 ; i < temp.size() ; i++ ) { 
                        if ( temp[i] < prev ) { 
                            prev = temp[i] ; 
                        }
                        else { 
                            return false ; 
                        }
                    }
                }
                temp.clear() ; 
                level++ ; 
                continue ; 
            }
            if ( curr->left != NULL ) { 
                q.push(curr->left) ; 
            }
            if ( curr->right != NULL ) { 
                q.push(curr->right) ; 
            }
        }   
        return true ; 
    }
    bool isEvenOddTree(TreeNode* root) { 
        if ( root == NULL ) { 
            return false ; 
        }
        vector <int> temp ;  
        int level = 0 ; 
        return Helper_function(root,temp,level) ; 
    }
};