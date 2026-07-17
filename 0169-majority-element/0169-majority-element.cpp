class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int e = nums[0];
        for ( int i = 0 ; i < n ; i++ ) {
            int count = 1 ;
            int frequency = 0 ;
            for ( int j = 0 ; j < i ; j++ ) { 
                if (nums[i] == nums[j]){ 
                    count++ ;
                }
            } 
            if (count == 1 ) { 
                for ( int k = 0 ; k < n ; k++ ) { 
                    if ( nums[i]==nums[k]) { 
                        frequency++ ;
                    }
                }
                if (frequency > n/2 ) { 
                    return nums[i] ;
                }
            }
        }
        return e ;
    }
};