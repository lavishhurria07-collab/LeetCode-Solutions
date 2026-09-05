/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) { 
        if ( head == NULL ) { 
            return NULL ; 
        }
        Node *newhead = new Node(head->val) ; 
        Node *oldtemp = head -> next ; 
        Node *newtemp = newhead ; 
        unordered_map <Node*,Node*> map ; 
        map[head] = newhead ; 
        while ( oldtemp != NULL ) { 
            Node *copynode = new Node(oldtemp->val) ; 
            map[oldtemp] = copynode ; 
            newtemp -> next = copynode ; 
            oldtemp = oldtemp -> next ; 
            newtemp = newtemp -> next ; 
        }
        oldtemp = head ; 
        newtemp = newhead ; 
        while ( oldtemp != NULL ) { 
            newtemp -> random = map[oldtemp->random] ; 
            newtemp = newtemp -> next ; 
            oldtemp = oldtemp -> next ; 
        }
        return newhead ; 
    } 
};