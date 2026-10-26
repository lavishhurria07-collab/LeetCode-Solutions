class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size() ; 
        int count_n = 0 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( nums[i] < 0 ) { 
                count_n++ ; 
            }
            else if ( nums[i] == 0 ) { 
                return 0 ; 
            }
        }
        if ( count_n % 2 == 0 ) { 
            return 1 ; 
        }
        return -1 ; 
    }
};