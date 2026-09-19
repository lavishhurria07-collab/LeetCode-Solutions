class Solution {
public:
    bool checkIfPangram(string sentence) {
        int frequency[26] = {0} ; 
        for ( int i = 0 ; i < sentence.size() ; i++ ) { 
            frequency[sentence[i]-'a']++ ; 
        }
        for ( int j = 0 ; j < 26 ; j++ ) { 
            if ( frequency[j] == 0 ) { 
                return false ; 
            }
        }
        return true  ;
    }
};