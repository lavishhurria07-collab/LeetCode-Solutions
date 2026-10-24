class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {  
        int n = nums.size() ; 
        int left1 = 0 ; 
        int right1 = n - 1 ; 
        int left2 = 0 ; 
        int right2 = n - 1 ; 
        int first = -1 ; 
        int second = -1 ; 
        while ( left1 <= right1 ) { 
            int mid = left1 + ( right1 - left1 ) / 2 ; 
            if ( nums[mid] == target ) { 
                second = mid ; 
                left1 = mid + 1 ; 
            }
            else if ( nums[mid] > target ) { 
                right1 = mid - 1 ; 
            } 
            else if ( nums[mid] < target ) { 
                left1 = mid + 1 ; 
            } 
        }
        while ( left2 <= right2 ) { 
            int mid = left2 + ( right2 - left2 ) / 2 ; 
            if ( nums[mid] == target ) { 
                first = mid ; 
                right2 = mid - 1 ; 
            }
            else if ( nums[mid] > target ) { 
                right2 = mid - 1 ; 
            } 
            else if ( nums[mid] < target ) { 
                left2 = mid + 1 ; 
            } 
        }
        return {first,second} ;  
    }
};