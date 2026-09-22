class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        int n = nums.size() ; 
        int left = 1 ; 
        int right = 1 ; 
        while ( left < n ) { 
            if ( nums[left] != nums[left-1] ) { 
                nums[right] = nums[left] ; 
                right++ ; 
            }
            left++ ; 
        }
        return right ; 
    }
};