class StockSpanner { 
private : 
    vector <int> stack ; 
    vector <int> prices ; 
    int top = -1 ; 
    int day = -1 ; 
public:
    StockSpanner() { 
    }
    int next(int price) { 
        while ( top != -1 && prices[stack[top]]  <= price ) { 
            stack.pop_back() ; 
            top-- ; 
        }
        day++ ; 
        int a ; 
        if ( top != -1 ) { 
            a = day - stack[top] ; 
        }
        else { 
            a = day + 1 ; 
        }
        top++ ; 
        stack.push_back(day) ; 
        prices.push_back(price) ;  
        return a ; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */