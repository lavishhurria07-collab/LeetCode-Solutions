class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end()) ; 
        int n = s.size() ; 
        int left = 0 ; 
        if ( s[left] == ' ' ) { 
            while ( left < n && isspace(s[left]) ) { 
                left++ ; 
            }
        }
        int right = left ; 
        while ( left < n && !isspace(s[left]) ) { 
            left++ ; 
        }
        return ( left - right ) ; 
    }
};