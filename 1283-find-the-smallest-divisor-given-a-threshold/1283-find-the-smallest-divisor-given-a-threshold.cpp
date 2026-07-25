class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ; 
        int start = 1 ;
        int end = *max_element(nums.begin(),nums.end()) ; 
        int ans = 0 ;
        while ( start <= end ) { 
            int k = start + ( end - start ) / 2 ;
            long long sum = 0 ;
            for ( int i = 0 ; i < n ; i++ ) { 
                if ( nums[i] % k == 0 ) { 
                    sum = sum + nums[i]/k ;
                }
                else { 
                    sum = sum + nums[i]/k + 1 ;
                }
            }
            if ( sum <= threshold ) {
                ans = k ;
                end = k - 1 ;

            }
            else { 
                start = k + 1 ; 
            }
        }
        return ans ;
    }
};