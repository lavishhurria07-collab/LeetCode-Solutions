class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { 
        int n = nums.size() ; 
        int sum = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        int min_len = INT_MAX ; 
        while ( right < n ) { 
            sum = sum + nums[right] ; 
            if ( sum >= target ) { 
                while ( sum >= target ) { 
                    int size = ( right - left + 1 ) ; 
                    min_len = min(min_len,size) ; 
                    sum = sum - nums[left] ; 
                    left++ ; 
                } 
            }
            right++ ; 
        }
        if ( min_len == INT_MAX ) { 
            return 0 ; 
        }
        return min_len ; 
    }
};