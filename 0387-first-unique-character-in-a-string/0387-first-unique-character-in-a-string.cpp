class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size() ; 
        int frequency[26] = {0} ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[s[i]-'a']++ ; 
        } 
        for ( int j = 0 ; j < n ; j++ ) { 
            if ( frequency[s[j]-'a'] == 1 ) { 
                return j ; 
            }
        }
        return -1 ; 
    }
};