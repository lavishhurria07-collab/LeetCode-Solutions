class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies [ 0 ] ;
        int n = candies.size() ;
        for ( int j : candies ) { 
            if ( j > max ) { 
                max = j ;
            }
        }
        vector <bool> result ;
        for ( int i = 0 ; i < n ; i++ ) { 
            int t = candies [ i ] + extraCandies ;
            if ( t >= max) { 
                bool h = true ;
                result.push_back(h) ;
            }
            else if ( t < max ){ 
                bool j = false ;
                result.push_back(j) ;
            }
        }
        return result ;
    }
};