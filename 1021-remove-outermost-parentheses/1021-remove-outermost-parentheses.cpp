class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0 ; 
        int n = s.size() ; 
        string ans ;  
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( s[i] == '(' ) { 
                if ( depth == 0 ) { 
                    depth++ ; 
                }
                else { 
                    ans = ans + '(' ; 
                    depth++ ; 
                }
            }
            else if ( s[i] ==')' ) { 
                depth-- ; 
                if ( depth > 0 ) { 
                    ans = ans + ')' ; 
                }
            }
        }    
        return ans ;    
    }
};