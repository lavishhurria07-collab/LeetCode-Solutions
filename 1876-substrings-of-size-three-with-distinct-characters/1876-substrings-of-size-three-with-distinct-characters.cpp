class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size() ; 
        int count = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        int frequency[26] = {0} ; 
        while ( right < n ) {
            frequency[s[right]-'a']++ ; 
                if ( ( right - left + 1 ) > 3 ) {
                    frequency[s[left]-'a']--; 
                    left++ ; 
                }
                if ( ( right- left + 1 ) == 3 ) {
                    if (( frequency[s[right]-'a'] == 1 ) && ( frequency[s[right-1]-'a']==1 ) && ( frequency[s[right-2]-'a']==1 ) ) {
                    count++ ; 
                }
            }
            right++ ; 
        }
        return count ; 
    }
};