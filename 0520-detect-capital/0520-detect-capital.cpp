class Solution {
public:
    bool detectCapitalUse(string word) {
        int frequency[52] = {0} ; 
        int count_upper = 0 ; 
        int count_lower = 0 ; 
        for ( int i = 0 ; i < word.size() ; i++ ) { 
            if ( isupper(word[i]) ) { 
                count_upper++ ; 
            } 
            else if ( islower(word[i]) ) { 
                count_lower++ ; 
            }
        }
        if ( count_lower == word.size() && count_upper == 0 ) { 
            return true ; 
        }
        else if ( count_upper == word.size() && count_lower == 0 ) { 
            return true ; 
        }
        else if ( count_upper == 1 && isupper(word[0]) ) { 
            return true ; 
        } 
        return false ; 
    }
};