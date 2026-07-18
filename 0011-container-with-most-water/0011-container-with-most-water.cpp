class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 
        int start = 0 ;
        int end = n - 1 ;
        int max_area = 0 ;
        while ( start < end ) {
            int area = 0 ; 
            if ( height[start] >= height[end] ) { 
                area = height[end] * (end-start) ;
                end-- ;
            }
            else { 
                area = height[start] * (end-start) ;
                start++ ;
            }
            if ( area > max_area ) { 
                max_area = area ;
            }
        } 
        return max_area ;
    }
};