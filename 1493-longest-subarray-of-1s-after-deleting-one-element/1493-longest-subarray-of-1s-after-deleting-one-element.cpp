class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        int count = 0 ;
        int max_len = 0 ;
        while ( right < n ) { 
            if ( nums[right] == 0 ) { 
                count++ ; 
            }
            while ( count > 1 ) { 
                if ( nums[left] == 0 ) { 
                    count-- ; 
                }
                left++ ; 
            }
            int size = right - left + 1 ; 
            max_len = max(max_len,size) ; 
            right++ ; 
        }
        return max_len - 1 ; 
    }
};