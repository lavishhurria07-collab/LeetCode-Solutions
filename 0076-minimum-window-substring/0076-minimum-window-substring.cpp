class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() ; 
        int m = t.size() ; 
        if ( n < m ) { 
            return "" ;
        }
        unordered_map<char,int> frequency_t ; 
        for ( int i = 0 ; i < m ; i++ ) {
            frequency_t[t[i]]++ ; 
        }
        int required = frequency_t.size() ; 
        unordered_map<char,int> frequency_s ; 
        int left = 0 ; 
        int right = 0 ; 
        int min_length = INT_MAX ; 
        int start = 0 ; 
        int formed = 0 ;
        while ( right < n ) {
            frequency_s[s[right]]++ ;
            if ( frequency_t.find(s[right]) != frequency_t.end() ) { 
                if (frequency_s[s[right]] == frequency_t[s[right]] ) { 
                    formed++ ; 
                }
            } 
            bool valid = false ; 
            if ( formed == required ) { 
                valid = true ; 
            }
            while ( valid == true ) { 
                if ( ( right - left + 1 ) < min_length ) { 
                    min_length = ( right - left + 1 ) ; 
                    start = left ; 
                }
                valid = false ;
                frequency_s[s[left]]-- ;  
                if ( frequency_t.find(s[left]) != frequency_t.end() ) { 
                    if ( frequency_t[s[left]] > frequency_s[s[left]] ) { 
                        formed-- ; 
                    }
                }
                left++ ;
                if ( formed == required ) { 
                    valid = true ; 
                }
            }
            right++ ; 
        }
        if ( min_length == INT_MAX ) { 
            return "" ; 
        }
        return s.substr(start,min_length) ; 
        }
};