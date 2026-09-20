class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) { 
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        if ( n == m ) { 
            for ( int i = 0 ; i < n ; i++ ) { 
                for ( int j = i ; j < n ; j++ ) { 
                    swap(matrix[i][j],matrix[j][i]) ; 
                }
            }
            return matrix ; 
        }
        else { 
            vector<vector<int>> ans ; 
            for ( int i = 0 ; i < m ; i++ ) { 
                vector<int> answer ; 
                for ( int j = 0 ; j < n ; j++ ) { 
                    answer.push_back(matrix[j][i]) ; 
                }
                ans.push_back(answer) ; 
            }
            return ans ;
        }
        return {{}} ;   
    }
};