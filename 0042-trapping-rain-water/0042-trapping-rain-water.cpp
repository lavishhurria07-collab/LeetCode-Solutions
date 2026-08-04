class Solution {
public:
    int trap(vector<int>& height) {
         int n = height.size() ; 
        int left = 0 ;
        int right = n - 1 ;
        int max_left = height[0] ;
        int max_right = height[n-1] ; 
        int water = 0 ; 
        while ( left < right ) {
            if ( height[left] >= max_left ) {
                max_left = height[left] ;
            }
            if ( height[right] >= max_right ) {
                max_right = height[right] ; 
            }
            if ( max_left <= max_right ) {
                water = water + max_left - height[left];
                left++;
            }
            else {
                water = water + max_right - height[right];
                right -- ; 
            }     
        }
        return water ;
    }
};