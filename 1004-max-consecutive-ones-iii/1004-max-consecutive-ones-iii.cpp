class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int count = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        int max_len = 0 ; 
        while ( right < n ) { 
            if ( nums[right] == 0 ) { 
                count++ ; 
            }
            if ( count > k ) { 
                while ( count > k ) {  
                    if ( nums[left] == 0 ) { 
                        count-- ; 
                    }
                    left++ ; 
                }
            }
            int size = right - left + 1 ; 
            max_len = max(max_len,size) ;
            right++ ; 
        }
        return max_len ; 
    }
};