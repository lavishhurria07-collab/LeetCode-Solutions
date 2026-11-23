/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution { 
public: 
    void Helper_Function ( Node* root , int &max_depth ) { 
        queue <Node*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            Node* curr = q.front() ; 
            q.pop() ; 
            if ( curr == NULL && q.size() != 0 ) { 
                max_depth++ ; 
                q.push(NULL) ; 
                continue ; 
            }
            else if ( curr == NULL && q.size() == 0 ) { 
                max_depth++ ; 
                return ; 
            }
            for ( int i = 0 ; i < curr->children.size() ; i++ ) { 
                q.push(curr->children[i]) ; 
            }
        }
    }
    int maxDepth(Node* root) { 
        if ( root == NULL ) { 
            return 0 ; 
        }
        int count = 0 ; 
        Helper_Function(root,count) ; 
        return count ; 
        
    }
};