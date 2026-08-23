class Solution {
public:
    int arrayPairSum(vector<int>& nums) { 
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        int left = n - 1 ;  
        int sum = 0 ; 
        while ( left > 0 ) { 
            sum = sum + min(nums[left],nums[left-1]) ; 
            left = left - 2 ; 
        }
        return sum ; 
    } 
};