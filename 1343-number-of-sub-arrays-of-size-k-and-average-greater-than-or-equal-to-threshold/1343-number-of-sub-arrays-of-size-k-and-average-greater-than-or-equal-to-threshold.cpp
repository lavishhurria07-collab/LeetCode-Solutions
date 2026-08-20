class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size() ; 
        int count = 0 ; 
        int sum = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( right < n ) {
            sum = sum + arr[right] ; 
            if ( ( right - left + 1 ) > k ) {
                sum = sum - arr[left] ;
                left++;
            }
            if ( ( right - left + 1 ) == k ) {
                int avg = sum / k ; 
                if ( avg >= threshold  ) {
                    count++ ;
                }
            }
            right++ ; 
        }
        return count ; 
    }
};