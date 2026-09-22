class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ; 
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        int top = 0 ; 
        int bottom = m - 1;
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left <= right && top <= bottom ) { 
            for ( int i = left ; i <= right ; i++ ) { 
                ans.push_back(matrix[top][i]) ; // top row left to right . 
            }
            top++ ; 
            for ( int i = top ; i <= bottom ; i++ ) { 
                ans.push_back(matrix[i][right]) ; // right col to bottom . 
            }
            right-- ; 
            if ( top <= bottom ) { 
                for ( int i = right ; i >= left ; i-- ) { 
                    ans.push_back(matrix[bottom][i]) ; // bottom row to left col . 
                }
                bottom-- ;
            } 
            if ( left <= right ) { 
                for ( int i = bottom ; i >= top ; i-- ) { 
                    ans.push_back(matrix[i][left]) ; // bottom to top in left col . 
                }
                left++ ;
            } 
        } 
        return ans ; 
    }
};