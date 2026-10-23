class Solution {
public:
    bool helper_function ( int &n ) { 
        if ( n == 0 || n < 0 ) { 
            return false ; 
        }
        if ( n == 1 ) { 
            return true ; 
        }
        if ( n % 3 != 0 ) { 
            return false ; 
        }
        n = n / 3 ; 
        return helper_function ( n ) ; 
    }
    bool isPowerOfThree(int n) {
        bool answer = helper_function(n) ; 
        return answer ; 
    }
};
