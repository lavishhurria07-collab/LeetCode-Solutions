class Solution {
public: 
    bool helper_function ( vector<vector<char>>& board , vector<vector<bool>>& visitor , int row , int col , string word , int index ) { 
        int n = board.size() ; 
        int m = board[0].size() ; 
        if ( row < 0 || col < 0 || row >= n || col >= m ) { 
            return false ; 
        }
        // Main checking condition .
        if ( visitor[row][col] == true ) { 
            return false ; 
        } 
        if ( board[row][col] != word[index] ) { 
            return false ; 
        }
        if ( index == word.size() - 1 ) { 
            return true ; 
        }
        visitor[row][col] = true ;  
        bool found = helper_function(board,visitor,row-1,col,word,index+1) || helper_function(board,visitor,row+1,col,word,index+1) || helper_function(board,visitor,row,col-1,word,index+1) || helper_function(board,visitor,row,col+1,word,index+1) ; 
        visitor[row][col] = false ; 
        return found ; 
    } 
    bool exist(vector<vector<char>>& board, string word) { 
        int n = board.size() ; 
        int m = board[0].size() ; 
        vector<vector<bool>> visitor ( n , vector<bool>(m,false) ) ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < m ; j++ ) { 
                if ( helper_function(board,visitor,i,j,word,0) ) { 
                    return true ; 
                }
            }
        }
        return false ; 
    }
};