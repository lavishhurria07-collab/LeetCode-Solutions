class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0 ;
        int max = INT_MIN ;
        int size = nums.size() ;
        for ( int i : nums ) { 
            current_sum = current_sum + i ;
            if ( current_sum > max ) { 
                max = current_sum ;
            } 
            if ( current_sum < 0 ) { 
                current_sum = 0 ;
            } 
        } 
        return max ;
    }
};