class MinStack { 
private : 
    vector <int> ans ; 
    vector <int> min ; 
    int top1 ; 
    int top2 ; 
public :
    MinStack() { 
        top1 = -1 ; 
        top2 = -1 ; 
    }  
    void push(int value) {
        top1++ ; 
        ans.push_back(value) ; 
        if ( top2 == -1 ) { 
            top2++ ; 
            min.push_back(value) ; 
        }
        else if ( min[top2] >= value ) { 
            top2++ ; 
            min.push_back(value) ; 
        }
    }
    void pop() {
        int a = ans[top1] ; 
        top1-- ; 
        ans.pop_back() ; 
        if ( a == min[top2] ) { 
            top2-- ; 
            min.pop_back() ; 
        }
    }
    int top() { 
        return ans[top1] ; 
    }
    int getMin() {
        return min[top2] ; 
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