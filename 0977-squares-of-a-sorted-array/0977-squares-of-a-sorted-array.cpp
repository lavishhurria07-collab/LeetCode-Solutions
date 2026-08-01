class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> ans(n) ; 
        int left = 0 ; 
        int right = n - 1 ; 
        int i = n - 1 ; 
        while ( right >= left ) { 
            int square = 0 ; 
            if ( abs(nums[left]) >= abs(nums[right]) ) { 
                square = nums[left] * nums[left] ; 
                ans[i] = square ;  
                left++ ; 
                i-- ; 
            } 
            else if ( abs(nums[left]) < abs(nums[right]) ) { 
                square = nums[right] * nums[right] ; 
                ans[i] = square ;  
                right-- ;  
                i-- ; 
            }
        } 
        return ans ; 
    }
};