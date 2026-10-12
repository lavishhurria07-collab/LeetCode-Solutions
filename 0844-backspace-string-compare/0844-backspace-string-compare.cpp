class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector <char> str1 ; 
        int top1 = - 1 ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            if ( s[i] != '#' ) { 
                top1++ ; 
                str1.push_back(s[i]) ; 
            }
            else if ( top1 != -1 ) { 
                str1.pop_back() ; 
                top1-- ; 
            }
        }
        vector <char> str2 ; 
        int top2 = - 1 ; 
        for ( int i = 0 ; i < t.size() ; i++ ) { 
            if ( t[i] != '#' ) { 
                top2++ ; 
                str2.push_back(t[i]) ; 
            }
            else if ( top2 != -1 ) { 
                str2.pop_back() ; 
                top2-- ; 
            }
        } 
        int a = str1.size() ; 
        int b = str2.size() ; 
        if ( a != b ) { 
            return false ; 
        }
        else { 
            for ( int i = 0 ; i < a ; i++ ) { 
                if ( str1[i] != str2[i] ) { 
                    return false ; 
                }
            }
        }
        return true ; 
    }
};