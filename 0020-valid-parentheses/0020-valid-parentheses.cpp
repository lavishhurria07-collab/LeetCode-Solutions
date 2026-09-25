class Solution {
public:
    bool isValid(string s) {
        vector<char> ans ; 
        if ( s.size() == 1 ) { 
            return false ; 
        }
        if ( s[0] == ')' || s[0] == '}' || s[0] == ']') { 
            return false ; 
        }
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[' ) { 
                ans.push_back(s[i]) ;  
            }
            if ( s[i] == ')' ) { 
                if ( ans.size() == 0 ) { 
                    return false ; 
                }
                if ( ans.back() != '(' ) { 
                    return false ; 
                }
                else { 
                    ans.pop_back() ; 
                }
            }
            if ( s[i] == '}' ) { 
                if ( ans.size() == 0 ) { 
                    return false ; 
                }
                if ( ans.back() != '{' ) { 
                    return false ; 
                }
                else { 
                    ans.pop_back() ; 
                }
            }
            if ( s[i] == ']' ) { 
                if ( ans.size() == 0 ) { 
                    return false ; 
                }
                if ( ans.back() != '[' ) { 
                    return false ; 
                }
                else { 
                    ans.pop_back() ; 
                }
            }
        } 
        if ( ans.size() == 0 ) { 
            return true ; 
        }
        return false ; 
    }
};