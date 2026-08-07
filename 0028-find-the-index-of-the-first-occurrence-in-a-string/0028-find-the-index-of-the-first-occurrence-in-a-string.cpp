class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0 ; 
        while ( start < haystack.length() ) { 
            if ( haystack.find(needle)!=string::npos ) { 
                return start ; 
            }
            start++ ; 
        }
        return -1 ; 
    }
};