/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class Node { 
public:
    int number ; 
    Node *next ; 
    Node *prev ; 
    Node ( int value ) { 
        number = value ; 
        next = NULL ; 
        prev = NULL ; 
    }
} ;  
class MyLinkedList {
public:
    Node *head ; 
    MyLinkedList() {
        head = NULL ; 
    }
    int get(int index) {
        if ( head == NULL || index < 0 ) { 
            return -1 ; 
        } 
        else { 
            Node *temp = head ; 
            int count = 0 ; 
            while ( temp != NULL ) { 
                if ( count == index ) { 
                    return temp -> number ; 
                }
                temp = temp -> next ; 
                count++ ; 
            }
        }
        return -1 ;
    }
    void addAtHead(int val) { 
        Node *newnode = new Node(val) ; 
        if ( head == NULL ) { 
            head = newnode ; 
            head -> next = NULL ; 
            head -> prev = NULL ; 
        }
        else { 
            newnode -> next = head ; 
            head -> prev = newnode ; 
            head = newnode ; 
        }
    }
    void addAtTail(int val) { 
        Node *newnode = new Node(val) ; 
        if ( head == NULL ) { 
            head = newnode ; 
            head -> next = NULL ; 
            head -> prev = NULL ; 
        }
        else { 
            Node *temp = head ; 
            while ( temp -> next != NULL ) { 
                temp = temp -> next ; 
            }
            temp -> next = newnode ; 
            newnode -> prev = temp ; 
            newnode -> next = NULL ; 
        }
    }
    void addAtIndex(int index, int val) { 
        Node *newnode = new Node(val) ; 
        if ( index < 0 ) { 
            return ; 
        }
        if ( index == 0 ) { 
            addAtHead(val) ;
            return ; 
        }
        if ( head == NULL && index == 0 ) { 
            addAtHead(val) ;  
            return ; 
        }
        int length = 0 ; 
        Node *temp = head ; 
        while ( temp != NULL ) { 
            temp = temp -> next ; 
            length++ ; 
        } 
        if ( length < index ) { 
            return ; 
        }
        else { 
            temp = head ; 
            for ( int i = 0 ; i < index - 1 && temp -> next != NULL ; i++ ) { 
                temp = temp -> next ; 
            }
            newnode -> next = temp -> next ; 
            newnode -> prev = temp ; 
            if ( temp ->next != NULL ) { 
                temp->next->prev = newnode ;  
            }
            temp -> next = newnode ;
        }
    }
    void deleteAtIndex(int index) {
        if ( head == NULL ) { 
            return ; 
        }
        else if ( index == 0 ) { 
            if ( head -> next != NULL ) { 
                head = head -> next ; 
                head -> prev = NULL ;
            }  
            else { 
                head = NULL ; 
            }
        }
        else { 
            int length = 0 ; 
            Node *temp = head ; 
            while ( temp != NULL ) { 
                temp = temp -> next ; 
                length++ ; 
            } 
            if ( index >= length ) { 
                return ; 
            }
            else if ( length - 1  == index ) { 
                temp = head ; 
                while ( temp->next->next != NULL ) { 
                    temp = temp -> next ;  
                }
                temp -> next = NULL ; 
            }
            else { 
                temp = head ; 
                for ( int i = 0 ; i < index - 1 && temp -> next != NULL ; i++ ) { 
                    temp = temp -> next ; 
                } 
                temp->next = temp->next->next ; 
                if ( temp -> next != NULL ) { 
                    temp->next->prev = temp ; 
                }
            }
        }
    }
};