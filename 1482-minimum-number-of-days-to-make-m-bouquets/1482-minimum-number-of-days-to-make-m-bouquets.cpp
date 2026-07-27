class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(),bloomDay.end()) ; 
        int end = *max_element(bloomDay.begin(),bloomDay.end()) ; 
        int ans = 0 ;
        int n = bloomDay.size() ; 
        long long s = (long long)m * k ; 
        if ( s > n ) { 
            return -1 ;
        }
        while ( start <= end ) { 
            int mid = start + ( end - start ) / 2 ; 
            int sum_bouquet = 0 ;
            int sum_flower = 0 ; 
            for ( int i = 0 ; i < n ; i++ ) {
                if ( bloomDay[i] <= mid ) { 
                    sum_flower++ ; 
                    if ( sum_flower == k ) { 
                        sum_bouquet++ ; 
                        sum_flower = 0 ;
                    }
                }
                else { 
                    sum_flower = 0 ;
                }
            }
            if ( sum_bouquet >= m) { 
                ans = mid ;
                end = mid - 1 ;
            }
            else { 
                start = mid + 1 ;
            }
        }
        return ans ; 
    }
};