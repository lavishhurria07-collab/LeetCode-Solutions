class MinStack {
private : 
    int ans[30000] ; 
    int min_stack[30000] ; 
    int top1 = -1 ; 
    int min_top = -1 ; 
public:
    MinStack() { 
    }  
    void push(int value) {
        int a = value ; 
        top1++ ; 
        ans[top1] = a ; 
        if ( min_top == -1 ) { 
            min_top++ ; 
            min_stack[min_top] = a ; 
        }
        else if ( min_stack[min_top] >= a ) { 
            min_top++ ; 
            min_stack[min_top] = a ; 
        }
    }
    void pop() {
        int b = ans[top1] ; 
        top1-- ; 
        if ( min_stack[min_top] == b ) { 
            min_top-- ; 
        }
    }
    int top() {
        return ans[top1] ;    
    }
    int getMin() {
        return min_stack[min_top] ;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */