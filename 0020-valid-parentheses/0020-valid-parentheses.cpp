class Solution {
public:
    bool isValid(string s) { 
        vector <char> stack ; 
        int top = -1 ; 
        if ( s.size() == 1 ) { 
            return false ; 
        }
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( ( s[i] == ')' || s[i] == ']' || s[i] == '}' ) && top == -1 )  { 
                return false ; 
            }
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' ) { 
                top++ ; 
                stack.push_back(s[i]) ; 
            }
            else if ( s[i] == ')' ) { 
                if ( stack[top] == '(' ) { 
                    stack.pop_back() ; 
                    top-- ; 
                }
                else { 
                    return false ; 
                }
            }
            else if ( s[i] == '}' ) { 
                if ( stack[top] == '{' ) { 
                    stack.pop_back() ; 
                    top-- ; 
                }
                else { 
                    return false ; 
                }
            }
            else if ( s[i] == ']' ) { 
                if ( stack[top] == '[' ) { 
                    stack.pop_back() ; 
                    top-- ; 
                }
                else { 
                    return false ; 
                }
            }
        }
        if ( top == -1 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
};