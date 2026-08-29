class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size() ; 
        int frequency[26] = {0} ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[s[i]-'a']++ ; 
            if(frequency[s[i]-'a'] == 2 ) { 
                return s[i] ; 
            }
        }
        return 'a' ; 
    }
};