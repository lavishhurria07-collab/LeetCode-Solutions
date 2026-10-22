class Solution {
public:
    string removeDuplicates(string s) { 
        vector <char> ans ; 
        int top = -1 ; 
        for ( int  i = 0 ; i < s.size() ; i++ ) { 
            if ( top == -1 ) { 
                top = 0 ; 
                ans.push_back(s[i]) ; 
            }
            else if ( ans[top] != s[i] ) { 
                top++ ; 
                ans.push_back(s[i]) ; 
            }
            else if ( ans[top] == s[i] ) { 
                top-- ; 
                ans.pop_back() ; 
            }
        }
        string answer ; 
        for ( int i = 0 ; i < ans.size() ; i++ ) { 
            answer = answer + ans[i] ; 
        }
        return answer ; 
    }
};