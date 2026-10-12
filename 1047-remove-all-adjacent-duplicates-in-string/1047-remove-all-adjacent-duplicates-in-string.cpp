class Solution {
public:
    string removeDuplicates(string s) {
        vector <char> stack ; 
        int top = -1 ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( top != -1 && stack[top] != s[i] ) {  
                top++ ; 
                stack.push_back(s[i]) ;
            }
            else if ( top == -1 ) { 
                top++ ; 
                stack.push_back(s[i]) ;
            }
            else if ( stack[top] == s[i] ) { 
                stack.pop_back() ; 
                top-- ; 
            }
        }
        string ans = "" ; 
        for ( int i = 0 ; i < stack.size() ; i++ ) { 
            ans = ans + stack[i] ; 
        }
        return ans ; 
    }
};