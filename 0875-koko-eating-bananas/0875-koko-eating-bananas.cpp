class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 ; 
        int n = piles.size() ; 
        int end = *max_element(piles.begin(), piles.end()); 
        int ans = 0 ;
        while ( start <= end ) { 
            int k = start + ( end - start ) / 2 ; 
            long long sum = 0 ;  
            for ( int i = 0 ; i < n ; i++ ) { 
                if ( piles[i] % k == 0 ) { 
                    sum = sum+piles[i]/k ; 
                }
                else { 
                    sum = sum + piles[i] / k + 1 ;
                }
            }
            if ( sum > h ) {
                start = k + 1 ;  
            }
            else { 
                ans = k ; 
                end = k - 1 ;
            }
        } 
        return ans ;
    }
};