class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size() ; 
        int m = s2.size();
        int frequency1[26]={0} ;
        for ( int i = 0 ; i < n ; i++ ) {
            frequency1[s1[i]-'a']++ ;
        }
        int frequency2[26]={0} ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( right < m ) {
            frequency2[s2[right]-'a']++;
            if ( ( right - left + 1 ) > n ) {
                frequency2[s2[left]-'a']--;
                left++ ; 
            }
            if ( ( right - left + 1 ) == n ) {
                int k = 0 ; 
                for ( int i = 0 ; i < 26 ; i++ ) {
                    if ( frequency1[i] != frequency2[i] ) {
                        k = 1 ; 
                        break ; 
                    }
                } 
                if ( k == 0 ) {
                    return true ; 
                }        
            }
            right++ ; 
        }
        return false ; 
    }
};