class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 ;
        int right = n - 1 ; 
        int max_area = 0 ;
        while ( left < right ) {
            int area = 0 ; 
            if ( height[left] < height[right] ) {
                area = ( right - left ) * height[left] ; 
                left++ ;
            }
            else {
                area = ( right - left ) * height[right];
                right--;
            }
            if ( area > max_area ) {
                max_area = area ;
            }
        }
        return max_area;
    }
};