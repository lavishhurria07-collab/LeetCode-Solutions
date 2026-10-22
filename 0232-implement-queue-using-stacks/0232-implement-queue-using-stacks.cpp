class MyQueue {
private : 
    stack <int> ans1 ; 
    stack <int> ans2 ; 
public:
    MyQueue() {
    }
    void push(int x) { 
        ans1.push(x) ; 
    }
    int pop() { 
        int n = ans1.size() ; 
        if ( ans2.empty() ) { 
            for ( int i = 0 ; i < n ; i++ ) { 
                int a = ans1.top() ; 
                ans2.push(a) ; 
                ans1.pop() ; 
            }
        }
        int b = ans2.top() ;  
        ans2.pop() ; 
        return b ; 
    }
    int peek() {
        if ( ans1.empty() ) { 
            return ans2.top() ; 
        } 
        else if ( ans2.empty() ) {  
            int n = ans1.size() ; 
            for ( int i = 0 ; i < n ; i++ ) { 
                int a = ans1.top() ; 
                ans2.push(a) ; 
                ans1.pop() ; 
            }
            return ans2.top() ; 
        }
        else { 
            return ans2.top() ; 
        }
    }
    bool empty() {
        if ( ans1.empty() && ans2.empty() ) { 
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