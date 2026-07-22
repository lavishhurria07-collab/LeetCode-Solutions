class Solution {
public:
    int mySqrt(int x) {
        if ( x == 0 ) { 
            return 0 ;
        }
        int start = 1 ; 
        int end = x ; 
        int ans = 0 ;
        while ( end >= start ) { 
            int mid = start + ( end - start ) / 2 ; 
            if ( x/mid < mid ) { 
                end = mid - 1 ; 
            }
            else if ( x/mid >= mid ) { 
                start = mid + 1 ;
                ans = mid ;
            }
        }
        return ans ;
    }
};