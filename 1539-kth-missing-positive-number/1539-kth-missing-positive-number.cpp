class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) { 
        int left = 0 ; 
        int right = arr.size() - 1 ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            int ans = arr[mid] - ( mid + 1 ) ; 
            if ( ans >= k ) { 
                right = mid - 1 ; 
            }
            else { 
                left = mid + 1 ; 
            }
        } 
        return left + k ; 
    }
};