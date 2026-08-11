class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size() ; 
        int m = t.size() ; 
        if ( m != n ) { 
            return false ; 
        }
        else { 
            int frequency[26] = {0} ; 
            for ( int i = 0 ; i < n ; i++ ) { 
                frequency[s[i]-'a']++ ; 
            }
            for ( int j = 0 ; j < m ; j++ ) { 
                frequency[t[j]-'a']-- ; 
            }
            for ( int k = 0 ; k < 26 ; k++ ) { 
                if ( frequency[k] != 0 ) { 
                    return false ; 
                }
            }
        }
        return true ; 
    }
};