class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size() ; 
        int frequency[501] = {0} ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[nums[i]]++ ; 
        }
        int count = 0 ; 
        for ( int i = 1 ; i <= 500 ; i++ ) { 
            if ( frequency[i] != 0 && frequency[i] % 2 == 0 ) { 
                int m = frequency[i] / 2 ; 
                count = count + m ; 
            }
        }
        if ( count == n / 2 ) { 
            return true ; 
        }
        else { 
            return false ; 
        } 
    }
};