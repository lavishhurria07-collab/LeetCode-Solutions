class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        int start = 0 ; 
        int n = matrix.size() ; 
        int end = n - 1 ; 
        while ( start <= end ) { 
            int mid = start + ( end - start ) / 2 ; 
            int col = matrix[mid].size() ; 
            if ( target < matrix[mid][0] ) { 
                end = mid - 1 ; 
            }
            else if ( target >= matrix[mid][0] ) { 
                if ( matrix[mid][col-1] >= target ) { 
                    int start1 = 0 ; 
                    int end1 = col - 1 ; 
                    while ( start1 <= end1 ) { 
                        int mid1 = start1 + ( end1 - start1 ) / 2 ; 
                        if ( matrix[mid][mid1] > target ) { 
                            end1 = mid1 - 1 ;
                        }
                        else if ( matrix[mid][mid1] < target ) { 
                            start1 = mid1 + 1 ; 
                        }
                        else { 
                            return true ; 
                        }
                    } 
                    return false ; 
                }
                else { 
                    start = mid + 1 ; 
                }
            }
        }
        return false ; 
    } 
}; 