class Solution {
public:
    int mySqrt(int x) { 
        if ( x == 1 ) { 
            return 1 ;
        }
        else if ( x == 0 ) { 
            return 0 ;
        }
        int start = 1 ; 
        int end = x-1 ; 
        int ans = 0 ;
        while ( end >= start ) {  
            int mid = ( start + end ) / 2 ; 
            if ( x / mid == mid ) {
                ans = mid ; 
                return ans ;
            }
            else if ( x / mid >= mid ) { 
                ans = mid ;
                start = mid + 1 ;
            }
            else {
                end = mid - 1 ;
            }
        }
        return ans ;
    }
};