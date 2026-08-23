class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> ans ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( ans.size() < n ) {  
            while ( left < n && nums[left] % 2 != 0 ) { 
                left++ ;  // even 
            }
            while ( right < n && nums[right] % 2 != 1 ) { 
                right++ ;   // odd
            }            
            ans.push_back(nums[left]) ;
            ans.push_back(nums[right]) ;
            left++ ; 
            right++ ; 
        }
        return ans ; 
    }
};