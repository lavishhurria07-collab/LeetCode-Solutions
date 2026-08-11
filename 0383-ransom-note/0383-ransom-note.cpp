class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size() ; 
        int m = magazine.size() ; 
        int frequency[26] = {0} ; 
        for ( int i = 0 ; i < m ; i++ ) { 
            frequency[magazine[i]-'a']++ ; 
        }
        for ( int j = 0 ; j < n ; j++ ) { 
            frequency[ransomNote[j]-'a']-- ;
        }
        for ( int k = 0 ; k < 26 ; k++ ) { 
            if ( frequency[k] < 0 ) { 
                return false ;
            }
        }
        return true ; 
    }
};