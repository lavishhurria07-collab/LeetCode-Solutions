class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size() ; 
        int left = 0 ; 
        int right = n - 1 ;   
        while ( right > left ) { 
            while ( nums[left] % 2 != 1 ) { 
                left++ ; 
            } // odd number 
            while ( nums[right] % 2 != 0 ) { 
                right-- ; 
            } // even number
            swap(nums[left],nums[right]) ; 
            left++ ; 
            right-- ; 
        }
        return nums; 
    }
};