class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) { 
        int start = 1 ; 
        int end = *max_element(piles.begin(),piles.end()) ; 
        int min_speed = INT_MAX ; 
        while ( start <= end ) { 
            int mid = start + ( end - start ) / 2 ; 
            long long hours = 0 ; 
            for ( int i = 0 ; i < piles.size() ; i++ ) { 
                hours = hours + piles[i] / mid ; 
                if ( piles[i] % mid != 0 ) { 
                    hours = hours + 1 ; 
                }
            }
            if ( hours > h ) { 
                start = mid + 1 ; 
            }
            else if ( hours <= h ) { 
                end = mid - 1 ; 
                min_speed = min(min_speed,mid) ; 
            }
        }
        return min_speed ; 
    }
};