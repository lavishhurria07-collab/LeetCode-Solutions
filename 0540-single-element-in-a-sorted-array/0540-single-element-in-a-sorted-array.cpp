class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { 
        int n = nums.size() ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left < right ) { 
            int mid = left + ( right - left ) / 2 ; 
            if (mid == 0) { 
                if ( nums[mid] == nums[mid+1] ) { 
                    left = mid + 2 ; 
                }
                else { 
                    return nums[0] ; 
                }
                continue ; 
            }
            if ( mid % 2 == 0 && mid + 1 < n ) { 
                if ( nums[mid] == nums[mid+1] ) { 
                    left = mid + 2 ; 
                } 
                else { 
                    right = mid ; 
                }
            }
            else if ( mid % 2 != 0 ) { 
                if ( nums[mid] == nums[mid-1] ) { 
                    left = mid + 1 ; 
                }
                else { 
                    right = mid ; 
                }
            }
        }
        return nums[right] ;  
    }
};