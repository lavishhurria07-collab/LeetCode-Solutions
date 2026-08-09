class Solution {
public:
    string reverseWords(string s) {
        string str = "" ; 
        int end = s.size() - 1 ; 
        while ( end >= 0 ) { 
            while ( ( end >= 0 ) && ( isspace(s[end]) ) ) { 
                end-- ; 
            } 
            if ( end < 0 ) { 
                break ;
            }
            int start = end ; 
            while ( ( start >= 0 ) && (!isspace(s[start]) ) ) { 
                start-- ;
            }
            if (str.size() > 0 ) { 
                str += " " ; 
            }
            str += s.substr(start+1,end-start) ;
            end = start - 1 ; 
        }
        return str ;
    }
};