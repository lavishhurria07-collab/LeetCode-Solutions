class Solution {
public:
    bool areOccurrencesEqual(string s) { 
        int frequency[26] = {0} ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            frequency[s[i]-'a']++ ; 
        }
        int freq = 0 ; 
        int m = 0 ; 
        for ( int i = 0 ; i < 26 ; i++ ) { 
            if ( frequency[i] != 0 && m == 0 ) { 
                freq = frequency[i] ; 
                m = 1 ; 
            }
            if ( m == 1 && frequency[i] != 0 && frequency[i] != freq ) { 
                return false ; 
            }
        } 
        return true ; 
    }
};