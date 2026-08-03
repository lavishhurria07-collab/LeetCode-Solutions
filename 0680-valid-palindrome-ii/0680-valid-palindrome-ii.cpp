class Solution {
public:
    bool isPalindrome( string &s, int left, int right ) {
        while ( left <= right ) { 
            if ( s[left] != s[right] ) { 
                return false ; 
            }
            left++ ; 
            right-- ; 
        }
        return true ;     
    }
    bool validPalindrome(string s) {
        int n = s.size() ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left <= right ) { 
            if ( s[left] == s[right] ) { 
                left++ ;
                right-- ; 
            } 
            else if ( s[left] != s[right] ) { 
                bool result1 = isPalindrome( s , left + 1, right) ;  
                bool result2 = isPalindrome( s , left , right - 1) ;  
                if ( ( result1 == true ) || ( result2 == true ) ) { 
                    return true ;
                } 
                else { 
                    return false ; 
                }
            }
        }
        return true ;  
    }
};