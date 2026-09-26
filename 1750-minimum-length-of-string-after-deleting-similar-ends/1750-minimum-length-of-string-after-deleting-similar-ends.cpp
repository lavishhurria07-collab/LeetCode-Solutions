class Solution {
public:
    int minimumLength(string s) {
        int n = s.size() ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left < right ) { 
            if ( s[left] == s[right] ) { 
                while ( left < right && s[left] == s[left+1] ) { 
                    left++ ; 
                }
                while ( left < right && s[right] == s[right-1] ) { 
                    right-- ; 
                } 
                left++ ; 
                right-- ; 
            }
            else { 
                break ; 
            }
        } 
        if ( right < left ) { 
            return 0 ; // jab string empty ho jaye . 
        }
        return ( right - left + 1 ) ; 
    }
};