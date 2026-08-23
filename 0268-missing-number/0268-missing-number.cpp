class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> frequency(n + 1, 0);
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[nums[i]]++ ; 
        }
        for ( int i = 0 ; i <= n ; i++ ) { 
            if ( frequency[i] == 0 ) { 
                return i ;
            }
        }
        return 0 ; 
        // int n = nums.size() ; 
        // int counter = 0 ; 
        // int i = 0 ;
        // sort(nums.begin(),nums.end()) ; 
        // while ( i < n ) { 
        //     if ( nums[i] != counter ) { 
        //         return counter ; 
        //     }
        //     i++ ; 
        //     counter++ ; 
        // }
        // return counter ; 
    }
};