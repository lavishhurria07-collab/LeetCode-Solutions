class Solution {
public:
    bool is_safe ( vector<string> &board , int n , int row , int col ) { 
        // horizontally check . 
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( board[row][j] == 'Q' ) { 
                return false ; 
            }
        }
        // vertiaclly chack . 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( board[i][col] == 'Q' ) { 
                return false ; 
            }
        }
        // left diagonally check . 
        for ( int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- ) { 
            if ( board[i][j] == 'Q' ) { 
                return false ; 
            }
        }
        // diagonally right check . 
        for ( int i = row , j = col ; i >= 0 && j < n ; i-- , j++ ) { 
            if ( board[i][j] == 'Q' ) { 
                return false ; 
            }
        }
        return true ; 
    }
    void nQueens ( vector<string> &board , int n , int row , vector<vector<string>> &ans , int &count ) { 
        if ( row == n ) { 
            count++ ; 
            return ; 
        }
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( is_safe(board,n,row,j) ) { 
                board[row][j] = 'Q' ; 
                nQueens(board,n,row+1,ans,count) ; 
                board[row][j] = '.' ; 
            }
        }
    }
    int totalNQueens ( int n ) { 
        vector<string> board ( n , string ( n , '.' ) ) ; 
        vector<vector<string>> ans ; 
        int row = 0 ;
        int count = 0 ; 
        nQueens(board,n,row,ans,count) ; 
        return count ; 
    }
};