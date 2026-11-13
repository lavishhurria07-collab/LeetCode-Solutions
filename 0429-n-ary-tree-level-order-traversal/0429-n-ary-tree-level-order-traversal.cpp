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
    void helper_function ( Node* root , vector <int> &ans , vector<vector<int>> &answer ) { 
        queue <Node*> q ; 
        q.push(root) ; 
        q.push(NULL) ; 
        while ( q.size() > 0 ) { 
            Node* curr = q.front() ; 
            q.pop() ; 
            if ( curr != NULL ) { 
                ans.push_back(curr->val) ; 
            } 
            if ( curr == NULL && q.size() != 0 ) { 
                q.push(NULL) ; 
                answer.push_back(ans) ; 
                ans.clear() ; 
                continue ; 
            } 
            else if ( curr == NULL && q.size() == 0 ) { 
                answer.push_back(ans) ; 
                return ; 
            } 
            for ( int i = 0 ; i < curr->children.size() ; i++ ) { 
                if ( curr->children[i] != NULL ) { 
                    q.push(curr->children[i]) ; 
                }
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) { 
        if ( root == NULL ) { 
            return {} ; 
        }
        vector<int> ans ; 
        vector<vector<int>> answer ; 
        helper_function(root,ans,answer) ; 
        return answer ; 
    }
};