class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1 ;
        long long power = n ;
        if ( power < 0 ) { 
            x= 1/x ;
            power = - power ;
        }
        while ( power > 0 ) { 
            int a = power % 2 ; 
            if ( a == 1 ) { 
                ans = ans * x ;
                x = x * x ;
            }
            else { 
                x = x * x ;
            }
            power = power / 2 ;
        }
        return ans ;
    }
};