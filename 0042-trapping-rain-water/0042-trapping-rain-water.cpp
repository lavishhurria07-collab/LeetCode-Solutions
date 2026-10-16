class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ; 
        vector <int> stack ; 
        int top = -1 ; 
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && height[stack[top]] < height[i] ) { 
                int base = height[stack[top]] ; 
                stack.pop_back() ; 
                top-- ; 
                if ( top != -1 ) { 
                    int a = height[stack[top]] ;
                    int w = min(a,height[i]) - base ; 
                    int width = i - stack[top] -1 ; 
                    int water = w * width ; 
                    sum = sum + water ; 
                }
            }
            top++ ; 
            stack.push_back(i) ; 
        }
        return sum ; 
    }
};