class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size() ; 
        vector <int> ans ;  
        for ( int i = 0 ; i < n ; i++ ) { 
            int index = INT_MAX ; 
            int valid = INT_MAX ; 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( intervals[i][1] <= intervals[j][0] ) { 
                    if ( valid > intervals[j][0] ) { 
                        valid = intervals[j][0] ; 
                        index = j ; 
                    }
                }
            }
            if ( index == INT_MAX ) { 
                ans.push_back(-1) ; 
            }
            else { 
                ans.push_back(index) ; 
            }
        }
        return ans ; 
    }
};