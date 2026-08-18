class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        int frequency = 0 ; 
        int max_ln = 0 ; 
        while ( right < n ) { 
            if ( nums[right] == 1 ) { 
                frequency++ ; 
            }
            if ( ( (right - left + 1 ) - frequency ) <= k ) { 
                max_ln = max( (right - left + 1 ) , max_ln ) ;  
            }
            while ( ( (right - left + 1 ) - frequency ) > k ) { 
                if ( nums[left] == 1 ) { 
                    frequency-- ; 
                }
                left++ ; 
            }
            right++ ; 
        }
        return max_ln ; 
    }
};