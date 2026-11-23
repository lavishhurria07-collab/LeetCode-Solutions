/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution { 
public: 
    void Helper_Function ( Node* root , vector <Node*> &answer ) { 
        queue <Node*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            Node* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                answer.push_back(curr) ; 
            } 
            if ( curr == NULL && q.size() != 0 ) { 
                for ( int i = 0 ; i < answer.size() - 1 ; i++ ) { 
                    Node* first = answer[i] ; 
                    Node* second = answer[i+1] ; 
                    first->next = second ; 
                }
                Node* first = answer.back() ; 
                first->next = NULL ; 
                q.push(NULL) ; 
                answer.clear() ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                for ( int i = 0 ; i < answer.size() - 1 ; i++ ) { 
                    Node* first = answer[i] ; 
                    Node* second = answer[i+1] ; 
                    first->next = second ; 
                }
                Node* first = answer.back() ; 
                first->next = NULL ; 
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
    Node* connect(Node* root) { 
        if ( root == NULL ) { 
            return NULL ; 
        }
        vector <Node*> answer ; 
        Helper_Function(root,answer) ; 
        return root ; 
    }
};