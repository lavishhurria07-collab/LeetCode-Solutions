class Solution {
public:
    int majorityElement(vector<int>& nums) { 
        int candidate = nums[0] ; 
        int frequency = 0 ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            if ( frequency == 0 ) { 
                candidate = nums[i] ; 
            }
            if ( nums[i] == candidate ) { 
                frequency++ ; 
            }
            else { 
                frequency-- ; 
            }
        }
        return candidate ; 
    }
};