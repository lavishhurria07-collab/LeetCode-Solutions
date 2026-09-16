class Solution {
public: 
    bool is_safe ( vector<vector<char>>& board , int n , int row , int col , char digit ) { 
        // horizontally check . 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( i != col && board[row][i] == digit ) { 
                return false ; 
            }
        }
        // vertically check . 
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( j != row && board[j][col] == digit ) { 
                return false ; 
            }
        }
        // grid check . 
        int row_st = ( row / 3 ) * 3 ; 
        int col_st = ( col / 3 ) * 3 ; 
        for ( int i = row_st ; i < ( row_st + 3 ) ; i++ ) { 
            for ( int j = col_st ; j < ( col_st + 3 ) ; j++ ) { 
                if ( ( i != row || j != col ) && board[i][j] == digit ) { 
                    return false ; 
                }
            }
        }
        return true ; 
    }
    bool isValidSudoku( vector<vector<char>>& board ) { 
        int n = board.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( board[i][j] != '.' ) { 
                    if( !is_safe(board,n,i,j,board[i][j] ) ) { 
                        return false ;
                    }   
                }
            }
        }
        return true ; 
    }
};