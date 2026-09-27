class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size() ;  
        int right = 0 ; 
        int left = 0 ; 
        int cost = 0 ; 
        int max_len = 0 ;
        while ( right < n ) { 
            int diff = s[right] - t[right] ; 
            if ( diff < 0 ) { 
                diff = -diff ; 
            }
            cost = cost + diff ;
            while ( cost > maxCost ) { 
                int sub = s[left] - t[left] ; 
                if ( sub < 0 ) { 
                    sub = -sub ; 
                }
                cost = cost - sub ; 
                left++ ; 
            }
            int size = right - left + 1 ; 
            max_len = max(max_len,size) ;  
            right++ ; 
        }
        return max_len ; 
    }
};