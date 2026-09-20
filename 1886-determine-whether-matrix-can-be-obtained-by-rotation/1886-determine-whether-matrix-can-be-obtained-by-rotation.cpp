class Solution {
public: 
    bool is_equal ( vector<vector<int>>& mat, vector<vector<int>>& target ) { 
        int n = mat.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( mat[i][j] != target[i][j] ) { 
                    return false ; 
                }
            }
        }
        return true ; 
    }
    vector<vector<int>> rotation_mat ( vector<vector<int>>& mat ) { 
        int n = mat.size() ; 
        vector<vector<int>> new_mat ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            vector<int> new_m ; 
            for ( int j = 0 ; j < n ; j++ ) { 
                new_m.push_back(mat[j][n-i-1]) ; 
            }
            new_mat.push_back(new_m) ; 
        }
        return new_mat ; 
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> ans = mat ; 
        int i = 0 ; 
        while ( i < 4 ) { 
            if (is_equal(ans,target) ) { 
                return true ; 
            } 
            ans = rotation_mat(ans) ; 
            i++ ;
        }
        return false ; 
    }
};