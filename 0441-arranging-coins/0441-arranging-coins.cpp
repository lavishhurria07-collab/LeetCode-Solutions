class Solution {
public:
    int arrangeCoins(int n) { 
        int left = 0 ; 
        int right = n ; 
        int answer = 0 ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            if ( ( 1LL * mid * ( mid + 1 ) ) / 2 > n ) { 
                right = mid - 1 ; 
            } 
            else { 
                answer = max(answer,mid) ; 
                left = mid + 1 ; 
            }
        }
        return answer ; 
    }
};