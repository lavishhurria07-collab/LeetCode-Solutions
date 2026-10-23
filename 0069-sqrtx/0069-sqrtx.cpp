class Solution {
public:
    int mySqrt(int x) { 
        int left = 0 ;
        int right = x ; 
        int answer = 0 ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            if ( mid == 0 ) { 
                left = mid + 1 ; 
            }
            else if ( mid > x / mid ) { 
                right = mid - 1 ;  
            } 
            else if ( mid <= x / mid ) { 
                answer = mid ; 
                left = mid + 1 ;  
            } 
        }
        return answer ; 
    }
};