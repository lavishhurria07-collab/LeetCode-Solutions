class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = nums[0] ; 
        for ( int i = 1 ; i < nums.size() ; i++ ) { 
            ans = ans ^ nums[i] ; 
        }
        unsigned int bit = (unsigned int)ans & (-(unsigned int)ans) ; 
        int ans1 = 0 ; 
        int ans2 = 0 ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            if ( ( nums[i] & bit ) == 0 ) { 
                ans1 = ans1 ^ nums[i] ; 
            }
            else { 
                ans2 = ans2 ^ nums[i] ; 
            }
        }
        return {ans1,ans2} ; 
    }
};