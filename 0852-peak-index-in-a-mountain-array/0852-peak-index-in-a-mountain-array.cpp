class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() ; 
        int left = 0 ; 
        int right = n - 2 ; 
        int mid ; 
        while ( left <= right && (mid+1) < ( n - 1) ) { 
            mid = left + ( right - left ) / 2 ; 
            if ( arr[mid] > arr[mid+1] ) { 
                right = mid - 1 ; 
            }
            else { 
                left = mid + 1 ;
            }
        }
        return left ; 
    }
};