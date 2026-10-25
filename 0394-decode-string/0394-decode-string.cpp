class Solution {
public:
    string decodeString(string s) { 
        int n = s.size() ; 
        stack <int> countstack ; 
        stack <string> stringstack ; 
        int currcount = 0 ;
        string currstring = "" ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( isdigit(s[i]) ) { 
                currcount = currcount * 10 + ( s[i] - '0' ) ; 
            } 
            else if ( isalpha(s[i]) ) { 
                currstring = currstring + s[i] ; 
            }
            else if ( s[i] == '[' ) { 
                countstack.push(currcount) ; 
                currcount = 0 ; 
                stringstack.push(currstring) ; 
                currstring = "" ; 
            }
            else if ( s[i] == ']' ) { 
                int a = countstack.top() ; 
                string temp = currstring ; 
                for ( int i = 1 ; i < a ; i++ ) { 
                    currstring = currstring + temp ; 
                }
                countstack.pop() ; 
                string ans = stringstack.top() ; 
                currstring = ans + currstring ; 
                stringstack.pop() ; 
            }
        }
        return currstring ; 
    }
};