class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        int n = board.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( board[i][j] == '.' ) { 
                    for ( int k = 1 ; k < 10 ; k++ ) { 
                        if ( is_safe ( board , n , i , j , k ) ) { 
                            board[i][j] = '0' + k ; 
                            if ( solveSudoku(board) ) { 
                                return true ; 
                            }
                        }
                        board[i][j] = '.' ; 
                    }
                    return false ;
                }
            }
        } 
        return true ; 
    }
    bool is_safe ( vector<vector<char>>& board , int n , int row , int col , int k ) { 
        // horizontally check . 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( board[row][i] == '0' + k ) { 
                return false ; 
            }
        }
        // vertically check . 
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( board[j][col] == '0' + k ) { 
                return false ; 
            }
        }
        // grid check . 
        int row_st = ( row / 3 ) * 3 ; 
        int col_st = ( col / 3 ) * 3 ; 
        for ( int i = row_st ; i < (row_st + 3) ; i++ ) { 
            for ( int j = col_st ; j < (col_st + 3) ; j++ ) { 
                if ( board[i][j] == '0' + k ) { 
                    return false ; 
                }
            }
        } 
        return true ; 
    }
};