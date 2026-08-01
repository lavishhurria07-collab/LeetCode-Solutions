class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans ; 
        int n = nums.size() ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( right >= left ) { 
            int square = 0 ; 
            if ( abs(nums[left]) >= abs(nums[right]) ) { 
                square = nums[left] * nums[left] ; 
                ans.push_back(square) ;  
                left++ ; 
            } 
            else if ( abs(nums[left]) < abs(nums[right]) ) { 
                square = nums[right] * nums[right] ; 
                ans.push_back(square) ; 
                right-- ;  
            }
        } 
        reverse(ans.begin(),ans.end()) ; 
        return ans ; 
    }
};