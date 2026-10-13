class MyQueue {
private : 
    int stack1[100] ; 
    int top1 = -1 ; 
    int top2 = -1 ;
    int stack2[100] ; 
public:
    MyQueue() {

    }
    void push(int x) { 
        top1++ ; 
        stack1[top1] = x ; 
    }
    int pop() { 
        if ( top2 == -1 ) { 
            while ( top1 >= 0 ) { 
                int val = stack1[top1] ; 
                top2++ ; 
                stack2[top2] = val ; 
                top1-- ;
            }
        } 
        int val = stack2[top2] ; 
        top2-- ; 
        return val ; 
    }
    int peek() {
        if ( top2 == -1 ) { 
            while ( top1 >= 0 ) { 
                int val = stack1[top1] ; 
                top2++ ; 
                stack2[top2] = val ; 
                top1-- ;
            }
        }
        return stack2[top2] ; 
    }
    bool empty() {
        if ( top2 == -1 && top1 == -1 ) { 
            return true ; 
        }
        return false ; 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */