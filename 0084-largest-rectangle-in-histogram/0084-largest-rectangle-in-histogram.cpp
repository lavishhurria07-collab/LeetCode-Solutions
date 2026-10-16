class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0 ; 
        int n = heights.size() ; 
        int top = -1 ; 
        vector <int> stack ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && heights[stack[top]] > heights[i] ) { 
                int a = heights[stack[top]] ; 
                top-- ; 
                stack.pop_back() ; 
                int area ;
                if ( top != -1 ) { 
                    area = a * ( i - stack[top] - 1 ) ;
                } 
                else { 
                    area = a * i ; 
                }
                max_area = max(max_area,area) ; 
            }
            top++ ; 
            stack.push_back(i) ; 
        }
        while ( top != -1 ) { 
            int a = heights[stack[top]] ; 
            top-- ; 
            stack.pop_back() ; 
            int area ;
            if ( top != -1 ) {
                int width = n - stack[top] - 1 ; 
                area = a * width ; 
                max_area = max(max_area,area) ; 
            }
            else { 
                area = a * n ; 
                max_area = max(max_area,area) ; 
            }
        }
        return max_area ; 
    }
};