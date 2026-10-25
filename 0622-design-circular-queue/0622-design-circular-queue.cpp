class MyCircularQueue { 
private : 
    vector <int> answer ; 
    int front ; 
    int rear ; 
    int count ; 
    int size ; 
public:
    MyCircularQueue(int k) {
        size = k ; 
        answer.resize(k) ; 
        front = -1 ; 
        rear = -1 ; 
        count = 0 ; 
    }
    
    bool enQueue(int value) {
        if ( count == size ) { 
            return false ; 
        }
        else if ( rear == -1 && front == -1 ) {  
            rear = 0 ; 
            front = 0 ; 
            answer[rear] = value ; 
            count++ ; 
        }
        else { 
            rear = ( rear + 1 ) % size ; 
            answer[rear] = value ; 
            count++ ; 
        }
        return true ; 
    }
    
    bool deQueue() {
        if ( front == -1 && rear == -1 ) { 
            return false ; 
        }
        else if ( count == 0 ) { 
            return false ; 
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
        else if ( count == 0 ) { 
            return -1 ; 
        }
        else { 
            return answer[front] ; 
        }
    }
    
    int Rear() {
        if ( rear == -1 ) { 
            return -1 ; 
        }
        else if ( count == 0 ) { 
            return -1 ; 
        }
        else { 
            return answer[rear] ; 
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */