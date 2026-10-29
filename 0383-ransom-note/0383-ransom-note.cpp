class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int frequency1[26] = {0} ; 
        int frequency2[26] = {0} ; 
        for ( int i = 0 ; i < ransomNote.size() ; i++ ) { 
            frequency1[ransomNote[i]-'a']++ ; 
        }
        for ( int i = 0 ; i < magazine.size() ; i++ ) { 
            frequency2[magazine[i]-'a']++ ; 
        }
        for ( int i = 0 ; i < ransomNote.size() ; i++ ) { 
            if ( frequency1[ransomNote[i]-'a'] > frequency2[ransomNote[i]-'a'] ) { 
                return false ; 
            }
        }
        return true ; 
    }
};