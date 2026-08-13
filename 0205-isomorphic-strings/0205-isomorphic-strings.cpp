class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp1; 
        int n = s.size() ; 
        int m = t.size() ; 
        if ( m != n ) { 
            return false ; 
        }
        else { 
            for ( int i = 0 ; i < m ; i++ ) { 
                if ( mp.find(s[i]) == mp.end() ) { 
                    mp[s[i]] = t[i] ; 
                }
                else { 
                    if ( mp[s[i]] != t[i] ) { 
                        return false ; 
                    }
                }
                if ( mp1.find(t[i]) != mp1.end() ) { 
                    if ( mp1[t[i]] != s[i] ) { 
                        return false ; 
                    }
                }
                else { 
                    mp1[t[i]] = s[i] ; 
                }
            }
        }
        return true ; 
    }
};