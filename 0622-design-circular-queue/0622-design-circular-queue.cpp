class MyCircularQueue { 
private : 
    int size ; 
    int rear ;
    int front ;  
    int count ; 
    vector <int> ans ; 
public:
    MyCircularQueue(int k) {
        size = k ; 
        count = 0 ; 
        rear = -1 ; 
        ans.resize(k) ; // help li thi .  
        front = -1 ; 
    }
    
    bool enQueue(int value) {
        if ( count == size ) { 
            return false ; 
        }
        else if ( rear == -1 && front == -1 ) { 
            rear = 0 ; 
            front = 0 ; 
            count++ ; 
            ans[rear] = value ; 
        }
        else { 
            rear = ( rear + 1 ) % size ;
            count++ ; 
            ans[rear] = value ; 
        }
        return true ; 
    }
    
    bool deQueue() {
        if ( front == -1 ) { 
            return false ; 
        }
        else if ( front == rear ) { 
            front = -1 ; 
            rear = -1 ; 
            count-- ; 
        }
        else {  
            front = ( front + 1 ) % size ; 
            count-- ; 
        }
        return true ; 
    }
    
    int Front() { 
        if ( front == -1 ) { 
            return -1 ; 
        }
        else { 
            return ans[front] ; 
        }
    }
    
    int Rear() {
        if ( rear == -1 ) { 
            return -1 ; 
        }
        else { 
            return ans[rear] ; 
        }
    }
    
    bool isEmpty() {
        if ( front == -1 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
    
    bool isFull() {
        if ( count == size )  { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */