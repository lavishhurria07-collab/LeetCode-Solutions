class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0 ; 
        int right = num ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            if ( mid == 0 ) { 
                left = mid + 1 ; 
            }
            else if ( mid > num / mid ) { 
                right = mid - 1 ; 
            }
            else if ( mid < num / mid ) { 
                left = mid + 1 ; 
            }
            else if ( mid == num / mid  && num % mid == 0 ) { 
                return true ; 
            } 
            else if ( mid == num / mid  && num % mid != 0 ) { 
                left = mid + 1 ; 
            }
        }
        return false ; 
    }
};