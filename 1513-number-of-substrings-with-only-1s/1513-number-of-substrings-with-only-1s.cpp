class Solution {
public:
    int numSub(string s) {
        int n = s.size() ; 
        long long count = 0 ; 
        int ptr = 0 ; 
        long long ans = 0 ; 
        while ( ptr < n ) { 
            if ( s[ptr] == '1' ) { 
                count++ ; 
            }
            else {  
                ans = ans + ( count * ( count + 1 ) ) / 2 ; 
                count = 0 ; 
            }
            ptr++ ; 
        } 
        if ( count != 0 ) { 
            ans = ans + ( count * ( count + 1 ) ) / 2 ; 
        }
        ans = ans % 1000000007 ; 
        return ans ; 
    }
};