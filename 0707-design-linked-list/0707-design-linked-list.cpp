// class ListNode { 
// public :
//     int value ; 
//     ListNode* next ; 
//     ListNode ( int x ) { 
//         value = x ; 
//         next = NULL ; 
//     }
// } ; 
class MyLinkedList {
public:
    ListNode* head ; 
    MyLinkedList() {
        head = NULL ; 
    }
    int get(int index) {
        int count = 0 ; 
        int value = -1 ; 
        ListNode* temp = head ; 
        while ( temp != NULL ) { 
            if ( count == index ) { 
                value = temp->val ; 
                return value ; 
            }
            temp = temp->next ; 
            count = count + 1 ; 
        }
        return value ; 
    }
    void addAtHead(int val) { 
        if ( head == NULL ) { 
            ListNode* node = new ListNode(val) ; 
            head = node ; 
        }
        else { 
            ListNode* node = new ListNode(val) ; 
            node->next = head ; 
            head = node ;  
        }
    }
    void addAtTail(int val) {
        if ( head == NULL ) { 
            ListNode* node = new ListNode(val) ; 
            head = node ; 
        }
        else { 
            ListNode* temp = head ; 
            while ( temp->next != NULL ) { 
                temp = temp->next ; 
            }
            ListNode* node = new ListNode(val) ; 
            temp->next = node ; 
        }
    }
    void addAtIndex(int index, int val) { 
        ListNode* t = head ; 
        int size = 0 ; 
        while ( t != NULL ) { 
            size = size + 1 ; 
            t = t->next ; 
        }
        if ( index == 0 || index < 0 ) { 
            addAtHead(val) ; 
            return ; 
        }
        if ( index == size ) { 
            addAtTail(val) ; 
            return ; 
        }
        else if ( index < size ) { 
            ListNode* temp = head ; 
            for ( int i = 0 ; i < index - 1 ; i++ ) { 
                temp = temp->next ; 
            }
            ListNode* node = new ListNode(val) ; 
            node->next = temp->next ; 
            temp->next = node ; 
            return ; 
        }
    } 
    void deleteAtIndex(int index) { 
        if ( head == NULL ) { 
            return ; 
        }
        ListNode* t = head ; 
        int size = 0 ; 
        while ( t != NULL ) { 
            size = size + 1 ; 
            t = t->next ; 
        }
        if ( index == 0 ) { 
            head = head->next ; 
        }
        else if ( index == size - 1 ) { 
            ListNode* temp = head ; 
            while ( temp->next->next != NULL ) { 
                temp = temp->next ; 
            }
            temp->next = NULL ; 
            return ; 
        }
        else if ( index < size ) { 
            ListNode* temp = head ; 
            for ( int i = 0 ; i < index - 1 ; i++ ) { 
                temp = temp->next ; 
            }
            temp->next = temp->next->next ; 
            return ; 
        }
        else { 
            return ; 
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */