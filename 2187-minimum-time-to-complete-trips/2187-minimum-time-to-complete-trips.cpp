class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size() ; 
        long long start = 1 ;
        int min_ele = *min_element(time.begin(),time.end()) ; 
        long long end = (long long)min_ele * totalTrips ; 
        long long ans = 0 ;
        while ( start <= end ) { 
            long long k = start + ( end - start ) / 2 ;
            long long sum = 0 ;
            for ( int i = 0 ; i < n ; i++ ) { 
                sum = sum + k / time[i] ; 
            }
            if ( sum >= totalTrips ) { 
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