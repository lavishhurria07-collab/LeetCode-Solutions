class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0 ;
        int temp = num ;
        for ( int i = 1 ; i <= num/2 ; i++ ) { 
            if (num % i == 0 ) { 
                sum = sum + i ;
            } 
        }
        if ( sum == temp ) { 
            return true ;
        }
        else { 
            return false ;
        }
    }
};