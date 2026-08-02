class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        int slow = 0 ; 
        int n = nums.size() ; 
        int fast = 1 ; 
        int count = 0 ; 
        while ( fast < n ) {  
            if ( nums[slow] != nums[fast] ) { 
                slow++ ;
                nums[slow] = nums[fast] ; 
                count++ ;  
            }            
            fast++ ; 
        }        
        return (slow+1) ; 
    }
};