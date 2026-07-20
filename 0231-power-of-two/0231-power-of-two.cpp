class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0 ;
        while ( n > 0 ) { 
            int a = n % 2 ; 
            if ( a == 1 ) { 
                count++ ; 
            }
            n = n / 2 ;
        }
        if ( count == 1 ) { 
            return true ;
        }
        else { 
            return false ;
        }
    }
};