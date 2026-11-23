class ProductOfNumbers { 
private : 
    vector <int> answer ; 
    int top ; 
public : 
    ProductOfNumbers() {
        top = -1 ; 
    }
    
    void add(int num) {
        top = top + 1 ; 
        answer.push_back(num) ; 
    }
    
    int getProduct(int k) { 
        int temp = top ; 
        int product = 1 ; 
        for ( int i = 0 ; i < k ; i++ ) { 
            product = product * answer[temp] ;  
            temp = temp - 1 ;
        }
        return product ; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */