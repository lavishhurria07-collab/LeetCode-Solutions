class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> ans ; 
        int count = 0 ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( ans.empty() ) { 
                if ( s[i] == '(' ) { 
                    ans.push(s[i]) ; 
                }
                else { 
                    count++ ; 
                }
            }
            else if ( s[i] == '(' ) { 
                ans.push(s[i]) ; 
            }
            else if ( s[i] == ')' ) { 
                if ( ans.top() == '(' ) { 
                    ans.pop() ; 
                }
                else { 
                    count++ ; 
                }
            }
        } 
        int n = ans.size() ; 
        return ( count + n ) ; 
    }
};