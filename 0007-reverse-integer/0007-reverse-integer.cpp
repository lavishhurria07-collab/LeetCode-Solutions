class Solution {
public:
    int reverse(int x) {
        long long  rev = 0 ; 
        long long temp = x ; 
        if ( temp <= 0 ) { 
            temp = - temp ;  
        }
       while ( temp > 0 ) { 
        int m = temp % 10 ; 
        if ( rev * 10 + m > INT_MAX ) { 
            return 0 ; 
        }
        rev = rev * 10 + m ; 
        temp = temp / 10 ; 
       }
       if ( x < 0 ) { 
        return (-rev) ; 
       }
       return rev ; 
    }
};