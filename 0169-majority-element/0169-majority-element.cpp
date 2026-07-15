class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size() ;
        int max_frequency = 0 ; 
        int a ;
        for ( int i = 0 ; i < size ; i++ ) { 
            int frequency = 0 ;
            for ( int j = 0 ; j < size ; j++ ) { 
                if ( nums [ i ] == nums [ j ] ) { 
                    frequency++ ;
                }
            } 
            if ( frequency > size / 2 ) { 
                return nums [ i ] ;
            } 
        }
        return 0 ; 
    }
};