class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        int counter = 0 ; 
        int i = 0 ;
        while ( i < n ) { 
            if ( nums[i] != counter ) { 
                return counter ; 
            }
            i++ ; 
            counter++ ; 
        }
        return counter ; 
    }
};