class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int range = *max_element(nums.begin(),nums.end()) ; 
        sort(nums.begin(),nums.end()) ; 
        int var = 1 ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            if ( nums[i] == var ) { 
                var++ ; 
            }
        }
        return var ; 
    }
};