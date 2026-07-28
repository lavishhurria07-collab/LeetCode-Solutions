class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() ; 
        int columns = matrix[0].size() ; 
        int row = 0 ; 
        int column = columns - 1 ; 
        while ( ( row < rows ) && ( column >= 0 ) ) { 
            if ( matrix[row][column] > target ) { 
                column-- ; 
            }
            else if ( matrix[row][column] < target ) { 
                row++ ; 
            }
            else { 
                return true ; 
            }
        }
        return false ;
    }
};