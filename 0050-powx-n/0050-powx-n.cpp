class Solution {
public: 
    double mypower(double x , long long n ) { 
        if ( n == 1 ) { 
            return x ; 
        }
        if ( n == 0 ) { 
            return 1 ; 
        }
        double half = mypower(x,n/2) ; 
        if ( n % 2 == 0 ) { 
            return half * half ; 
        }
        if ( n % 2 == 1 ) { 
            return half * half * x ; 
        }
        return half * half ; 
    }
    double myPow(double x, int n) {
        if ( n >= 0 ) { 
            long long m = (long long) n ; 
            return mypower(x,m) ; 
        }
        else { 
            long long m = - ( long long ) n ; 
            return 1 / mypower(x,m) ; 
        }
        return 0.00000 ; 
    }
};