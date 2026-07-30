class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ; 
        int i = n - 2 ; // previous element .
        int j = n - 1 ; // next element . 
        while ( i >= 0 ) { 
            if ( nums[i] >= nums[j] ) { 
                i-- ; 
                j-- ;  
            }
            else {   
                for ( int k = n - 1 ; k >= j ; k-- ) { 
                    if ( nums[k] > nums[i] ) { 
                        swap(nums[i],nums[k]) ; 
                        reverse(nums.begin()+i+1,nums.end()) ; 
                        return ;  
                    }
                } 
            }
        }
        reverse(nums.begin(),nums.end()) ; 
    }
};