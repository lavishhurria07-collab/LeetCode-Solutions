class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size() ; 
        int array[26] = {0} ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            array[s[i]-'a']++ ; 
        }
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( array[s[i]-'a'] == 1 ) { 
                return i ; 
            } 
        }
        return -1 ; 
    }
};