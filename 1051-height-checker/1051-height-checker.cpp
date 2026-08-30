class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector <int> expected ; 
        int n = heights.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            expected.push_back(heights[i]) ; 
        }
        int count = 0 ; 
        sort(expected.begin(),expected.end()) ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( heights[i] != expected[i] ) { 
                count++ ; 
            }
        }
        return count ; 
    }
};