class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size() ; 
        int left = 0 ; 
        int right = n  ; 
        sort(nums.begin(),nums.end()) ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            int count = 0 ; 
            for ( int i = 0 ; i < n ; i++ ) { 
                if ( nums[i] >= mid ) { 
                    count++ ; 
                }
            }
            if ( count == mid ) { 
                return mid ; 
            }
            else if ( count > mid ) { 
                left = mid + 1 ; 
            }
            else if ( count < mid ) { 
                right = mid - 1 ; 
            }
        }
        return -1 ; 
    }
};