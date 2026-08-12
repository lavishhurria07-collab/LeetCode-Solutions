class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size() ; 
        int m = t.size() ;
        int frequency1[26] = {0} ; 
        for ( int i = 0 ; i < n ; i++ ) {
             frequency1[s[i]-'a']++; 
        }
        for ( int j = 0 ; j  < m ; j++ ) {
            frequency1[t[j]-'a']--;
        }
        for ( int k = 0 ; k < m ; k++ ) {
            if ( frequency1[t[k]-'a'] == -1 ) {
                return t[k] ; 
            }
        }
        return 'a' ; 
    }
};