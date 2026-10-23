// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1 ; 
        int right = n ; 
        int answer = n ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            bool a = isBadVersion(mid) ; 
            if ( a == true ) { 
                answer = min(answer,mid) ; 
                right = mid - 1 ; 
            } 
            else { 
                left = mid + 1 ; 
            }
        } 
        return answer ; 
    }
};