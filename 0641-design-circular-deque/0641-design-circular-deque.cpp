class MyCircularDeque { 
private : 
    int size ; 
    vector <int> ans ; 
    int front ; 
    int rear ; 
    int count ; 
public:
    MyCircularDeque(int k) {
        size = k ; 
        ans.resize(k) ; 
        front = -1 ; 
        rear = -1 ; 
        count = 0 ; 
    }
    
    bool insertFront(int value) { 
        if ( count == size ) { 
            return false ; 
        }
        if ( front == -1 && rear == -1 ) { 
            front = 0 ; 
            rear = 0 ; 
            ans[front] = value ;
            count++ ; 
            return true ; 
        }
        else { 
            front = ( front - 1 + size ) % size ; 
            ans[front] = value ; 
            count++ ; 
            return true ; 
        }
        return true ; 
    }

    bool insertLast(int value) {
        if ( count == size ) { 
            return false ; 
        }
        if ( front == -1 && rear == -1 ) { 
            front = 0 ; 
            rear = 0 ; 
            ans[rear] = value ; 
            count++ ; 
            return true ; 
        }
        else { 
            rear = ( rear + 1 ) % size ; 
            ans[rear] = value ; 
            count++ ; 
            return true ; 
        }
        return true ;
    }
    
    bool deleteFront() { 
        if ( count == 1 ) { 
            front = -1 ; 
            rear = -1 ; 
            count-- ; 
            return true ; 
        }
        if ( front == -1 && rear == -1 ) { 
            return false ; 
        } 
        else {  
            front = ( front + 1 ) % size ; 
            count-- ; 
            return true ;
        } 
        return true ; 
    }
    
    bool deleteLast() { 
        if ( count == 1 ) { 
            front = -1 ; 
            rear = -1 ; 
            count-- ; 
            return true ; 
        }
        if ( front == -1 && rear == -1 ) { 
            return false ; 
        }
        else { 
            rear = ( rear -1 + size ) % size ; 
            ans.pop_back() ; 
            count-- ; 
            return true ; 
        }
        return true ; 
    }
    
    int getFront() {
        if ( front == -1 && rear == -1 ) { 
            return -1 ; 
        }
        else { 
            return ans[front] ; 
        }
    }
    
    int getRear() {
        if ( front == -1 && rear == -1 ) { 
            return -1 ; 
        }
        else { 
            return ans[rear] ; 
        }
    }
    
    bool isEmpty() {
        if ( count == 0 ) { 
            return true ; 
        }
        return false ; 
    }
    
    bool isFull() {
        if ( count == size ) { 
            return true ; 
        }
        return false ; 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */