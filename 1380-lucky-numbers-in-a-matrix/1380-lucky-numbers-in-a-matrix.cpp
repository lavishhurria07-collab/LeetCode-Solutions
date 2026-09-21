class Solution {
public:
    bool lucky ( int number , vector<vector<int>>& matrix , int row , int col ) { 
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( number > matrix[row][i] ) { // checking for row element . 
                return false ; 
            }
        }
        for ( int i = 0 ; i < m ; i++ ) { 
            if ( number < matrix[i][col] ) { // checking for column element . 
                return false ; 
            }
        }
        return true ;
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) { 
        vector<int> ans ; 
        int m = matrix.size() ; 
        int n = matrix[0].size() ; 
        for ( int i = 0 ; i < m ; i++ ) { 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( lucky( matrix[i][j] , matrix , i , j ) ) { 
                    ans.push_back(matrix[i][j]) ; 
                }
            }
        }
        return ans ; 
    }
};