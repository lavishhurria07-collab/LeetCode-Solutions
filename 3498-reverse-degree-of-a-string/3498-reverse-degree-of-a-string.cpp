class Solution {
public:
    int reverseDegree(string s) { 
        int sum = 0 ; 
        int n = s.size() ; 
        for ( int i = 0 ; i < n ; i++ ) {  
            int backward = 123 - s[i] ; 
            int product = ( i + 1 ) * backward ;  
            sum = sum + product ; 
        }
        return sum ; 
    }
};