class Solution {
public:
    int maxDistance(vector<int>& position, int m) { 
        int n = position.size() ; 
        int start = 1 ;
        int max_el = *max_element(position.begin(),position.end()) ;
        int min_el = *min_element(position.begin(),position.end()) ; 
        int end = max_el - min_el ;
        int ans = 0 ;
        sort(position.begin(),position.end());
        while ( start <= end ) { 
            int k = start + ( end - start ) / 2 ;
            int last_placed = position[0] ; 
            int count = 1 ; 
            for ( int i = 1 ; i < n ; i++ ) { 
                if ( position[i] >= last_placed + k ) { 
                    count++ ; 
                    last_placed = position[i] ; 
                }
            } 
            if ( count >= m ) { 
                ans = k ;
                start = k + 1 ;  
            }
            else { 
                end = k - 1 ;
            }
        } 
        return ans ; 
    }
};