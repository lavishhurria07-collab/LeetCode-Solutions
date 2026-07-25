class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size() ; 
        int start = *max_element(weights.begin(),weights.end() ) ; 
        int end = 0 ;
        for ( int i = 0 ; i < n ; i++ ) { 
            end = end + weights[i] ;
        } 
        int ans = 0 ;
        while ( start <= end ) { 
            int k = start + ( end - start ) / 2 ;
            int sum_weights = 0 ;
            int result = 1 ;
            for ( int i = 0 ; i < n ; i++ ) { 
                sum_weights = sum_weights + weights[i] ;
                if ( sum_weights > k ) { 
                    sum_weights = weights[i] ; 
                    result++ ;
                }
            }
            if ( result <= days ) { 
                end = k - 1 ; 
                ans = k ;
            }
            else { 
                start = k + 1 ;
            }
        }
        return ans ;
    }
};