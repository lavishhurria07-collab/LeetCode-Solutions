class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n ; 
        int sum = 0 ; 
        int product = 1 ; 
        while ( n > 0 ) { 
            int m = n % 10 ; 
            sum = sum + m ; 
            product = product * m ; 
            n = n / 10 ; 
        }
        int k = sum + product ; 
        if ( temp % k == 0 ) { 
            return true ;
        }
        else { 
            return false ; 
        }
    }
};