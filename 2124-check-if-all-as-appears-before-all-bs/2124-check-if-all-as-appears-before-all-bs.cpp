class Solution {
public:
    bool checkString(string s) { 
        if ( s.size() == 1 && s[0] == 'a' ) { 
            return true ; 
        }
        int index = -1 ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( s[i] == 'b' ) { 
                index = i ; 
                break ; 
            }
        }
        if ( index == -1 ) { 
            return true ; 
        }
        for ( int j = index ; j < s.size() ; j++ ) { 
            if ( s[j] == 'a' ) { 
                return false ; 
            }
        }
        return true ; 
    }
};