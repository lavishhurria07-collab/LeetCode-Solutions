class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0 ;
        int n = nums.size() ; 
        int end = n - 1 ;
        vector <int> ans = { -1,-1 } ;
        if ( n == 0 ) { 
            return ans ;
        }
        if ( n == 1 ) {
            if ( nums[0] == target ) { 
                ans[0]=0;
                ans[1]=0;
                return ans ;
            } 
            else { 
                return ans ;
            }
        }
        while ( start <= end ) {
            int mid = start + ( end - start ) / 2 ; 
            if ( nums[mid] >= target ) { 
                end = mid - 1 ;
            }
            else if ( nums[mid] < target ) { 
                start = mid + 1 ;
            }
        }
        if ( start == n ) { 
            return {-1,-1} ;
        }
        else if ( nums[start] == target ) { 
            ans[0] = start ; 
            int start1 = start ; 
            int end = n - 1 ; 
            while ( start1 <= end ) { 
                int mid = start1 + ( end - start1 ) / 2 ; 
                if ( nums[mid] <= target ) { 
                    start1 = mid + 1 ;
                }
                else if ( nums[mid] > target ) { 
                    end = mid - 1 ; 
                }
            }
            ans[1] = end ; 
        }
        else { 
            return {-1,-1} ; 
        }
        return ans ;
    }
};