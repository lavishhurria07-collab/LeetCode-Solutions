class CustomStack { 
private :  
    vector <int> stack ; 
    int top ; 
    int size ; 
public : 
    CustomStack(int maxSize) { 
        top = -1 ; 
        size = maxSize ; 
    }
    
    void push(int x) {
        if ( top != size - 1 ) { 
            top++ ; 
            stack.push_back(x) ; 
        }
    }
    
    int pop() {
        if ( top == -1 ) { 
            return -1 ; 
        }
        else { 
            int a = stack[top] ; 
            stack.pop_back() ; 
            top-- ; 
            return a ; 
        }
    }
    
    void increment(int k, int val) {
        for ( int i = 0 ; ( i < k && i <= top ) ; i++ ) { 
            stack[i] = stack[i] + val ; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */