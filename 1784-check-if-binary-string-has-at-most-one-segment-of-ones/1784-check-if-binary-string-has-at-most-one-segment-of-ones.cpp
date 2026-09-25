class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size() ; 
        int point = 0 ; 
        int count = 0 ; 
        while ( point < n ) { 
            if ( s[point] == '0' ) { 
                point++ ; 
            }
            if ( s[point] == '1' ) { 
                count++ ; 
                while ( point < n && s[point] == '1' ) { 
                    point++ ; 
                }
            }
        }
        if ( count == 1 ) { 
                return true ; 
            }
        return false ; 
    }
};