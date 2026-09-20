class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0 ; 
        int n = mat.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( i == j ) { 
                    sum = sum + mat[i][j] ; 
                }
            }
        }
        for ( int i = 0 ; i < n ; i++ ) { 
            sum = sum + mat[i][n-1-i] ;
        }
        if ( n % 2 != 0 ) { 
            sum = sum - mat[n/2][n/2] ; 
        } 
        return sum ; 
    }
};