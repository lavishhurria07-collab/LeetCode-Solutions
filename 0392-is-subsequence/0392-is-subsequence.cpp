class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size() ; 
        int pointer1 = 0 ; 
        int m = s.size() ; 
        int pointer2 = 0 ;
        int count = 0 ; 
        while ( ( pointer1 < n ) && ( pointer2 < m ) ) { 
            if ( s[pointer2] == t[pointer1] ) { 
                count++ ; 
                pointer2++ ; 
            } 
            pointer1++ ; 
        }
        if ( pointer2 == m ) { 
            return true ; 
        }    
        return false ; 
    }
};