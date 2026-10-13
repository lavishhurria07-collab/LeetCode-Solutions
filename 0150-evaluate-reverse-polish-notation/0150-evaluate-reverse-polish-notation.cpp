class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans[10000] ; 
        int top = -1 ;  
        int n = tokens.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*" ) { 
                top++ ; 
                ans[top] = stoi(tokens[i]) ; 
            }
            else if ( tokens[i] == "+" ) { 
                int a = ans[top] ; 
                top-- ; 
                int b = ans[top] ; 
                int c = a + b ; 
                ans[top] = c ;  
            }
            else if ( tokens[i] == "-" ) { 
                int a = ans[top] ; 
                top-- ; 
                int b = ans[top] ; 
                int c = b - a ; 
                ans[top] = c ;  
            }
            else if ( tokens[i] == "*" ) { 
                int a = ans[top] ; 
                top-- ; 
                int b = ans[top] ; 
                int c = a * b ; 
                ans[top] = c ;  
            }
            else if ( tokens[i] == "/" ) { 
                int a = ans[top] ; 
                top-- ; 
                int b = ans[top] ; 
                int c = b / a ; 
                ans[top] = c ;  
            }
        }
        return ans[top] ; 
    }
};