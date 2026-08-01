class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() ; 
        int element = 0 ;
        int non = 0 ; 
        while ( element < n ) { 
            if ( nums[element] != 0 ) { 
                swap(nums[element],nums[non]) ; 
                non++ ; 
            } 
            element++ ; 
        } 
    }
};