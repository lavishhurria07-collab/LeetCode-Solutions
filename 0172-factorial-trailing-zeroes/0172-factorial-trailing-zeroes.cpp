class Solution {
public:
    int trailingZeroes(int n) { 
        int count5 = 0 ; 
        for ( int i = 1 ; i <= n ; i++ ) { 
            if ( i % 5 == 0 ) { 
                int num = i ; 
                while ( num % 5 == 0 ) { 
                    num = num / 5 ; 
                    count5++ ; 
                }
            }
        }
        return count5 ; 
    }
};