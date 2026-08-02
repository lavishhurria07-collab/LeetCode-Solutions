class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0 ; 
        int n = nums.size() ; 
        int fast = 0 ; 
        while ( fast < n ) { 
            if ( nums[fast] != val ) { 
                nums[slow] = nums[fast] ; 
                slow++ ; 
            } 
            fast++ ; 
        }
        return ( slow ) ; 
    }
};