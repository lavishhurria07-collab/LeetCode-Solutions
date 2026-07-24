class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0 ; 
        int n = nums.size() ; 
        int end = n - 1 ; 
        int ans = nums[0] ;
        while ( start <= end ) { 
            int mid = start + ( end - start ) / 2 ; 
            if ((nums[start]<=nums[mid]) && (nums[mid]<=nums[end])) { 
                return nums[start] ;
            }
            else { 
                if (nums[start] <= nums[mid]) { 
                    start = mid + 1 ;
                }
                else { 
                    end = mid ;
                }
            }
        }
        return 0 ;
    }
};