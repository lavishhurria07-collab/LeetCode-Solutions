class Solution {
public: 
    bool no_of_digits( int n ) { 
        int count = 0 ; 
        while ( n > 0 ) { 
            count++ ; 
            n = n / 10 ; 
        }
        if ( count % 2 == 0 ) { 
            return true ;
        }
        return false ; 
    }
    int findNumbers(vector<int>& nums) {
        int digits = 0 ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            bool ans = no_of_digits(nums[i]) ; 
            if ( ans == true ) { 
                digits++ ; 
            }
        }
        return digits ; 
    }
};