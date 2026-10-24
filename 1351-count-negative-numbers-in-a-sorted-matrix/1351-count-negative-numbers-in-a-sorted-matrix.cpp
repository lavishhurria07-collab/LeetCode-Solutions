class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        int count = 0 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            int left = 0 ; 
            int right = m - 1 ; 
            int index = INT_MAX ; 
            while ( left <= right ) { 
                int mid = left + ( right - left ) / 2 ; 
                if ( grid[i][mid] > 0 ) { 
                    left = mid + 1 ; 
                }
                else if ( grid[i][mid] < 0 ) { 
                    right = mid - 1 ; 
                    index = min(index,mid) ; 
                } 
                else if ( grid[i][mid] == 0 ) { 
                    left = mid + 1 ; 
                }
            }
            if ( index == INT_MAX ) { 
                index = m ; 
            }
            count = count + ( m - index ) ; 
        }
        return count ; 
    }
};