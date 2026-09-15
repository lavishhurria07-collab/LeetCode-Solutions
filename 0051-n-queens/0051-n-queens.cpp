class Solution {
public:
    bool is_safe ( vector<string> &board ,int row , int col , int n ) { 
        // Horizontally check . 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( board[row][i] == 'Q' ) { 
                return false ; 
            }
        }
        // Vertically check . 
        for (int j = 0 ; j < n ; j++ ) { 
            if ( board[j][col] == 'Q' ) { 
                return false ; 
            }
        }
        // Left Daigonally check . 
        for ( int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- ) { 
            if ( board[i][j] == 'Q' ) { 
                return false ; 
            }
        } 
        // Right Daigonally check . 
        for ( int i = row , j = col ; i >= 0 && j < n ; i-- , j++ ) { 
            if ( board[i][j] == 'Q' ) { 
                return false ; 
            }
        }
        return true ; 
    }
    void nQueens ( vector<string> &board , int n , int row , vector<vector<string>> &ans) { 
        if ( row == n ) { 
            ans.push_back({board}) ; 
            return ; 
        }
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( is_safe(board,row,j,n) ) { 
                board[row][j] = 'Q' ; 
                nQueens(board,n,row+1,ans) ; 
                board[row][j] = '.' ; 
            }
        }      
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ; 
        vector<string> board ( n , string( n , '.' ) ) ; 
        int row = 0 ; 
        nQueens(board,n,row,ans) ; 
        return ans ; 
    }
};