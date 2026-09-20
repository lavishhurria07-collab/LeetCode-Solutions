class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) { 
        int n = logs.size() ;  
        int max_pop = 0 ; 
        int year ; 
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        for ( int i = 0 ; i < n ; i++ ) { 
            int count = 0 ; 
            for ( int j = 0 ; j < n ; j++ ) { 
                if ( logs[i][0] >= logs[j][0] && logs[i][0] < logs[j][1] ) { 
                    count++ ; 
                }
            }
            if ( max_pop < count ) { 
                year = logs[i][0] ; 
                max_pop = count ; 
            } 
        }
        return year ; 
    }
};