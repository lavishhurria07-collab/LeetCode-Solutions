class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = -DBL_MAX ; 
        int n = nums.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        double sum = 0 ; 
        while ( right < n ) { 
            sum = sum + nums[right] ; 
            if ( ( right - left + 1 ) > k ) { 
                sum = sum - nums[left] ; 
                left++ ; 
            }
            if ( ( right - left + 1 ) == k ) { 
                double avg = sum / k ; 
                max_avg = max(max_avg,avg) ;  
            } 
            right++ ; 
        }
        return max_avg ; 
    }
};