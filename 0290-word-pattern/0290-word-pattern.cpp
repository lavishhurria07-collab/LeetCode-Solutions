class Solution {
public:
    bool wordPattern(string pattern, string s) { 
        vector<string> words ; 
        stringstream ss(s) ; 
        string word ; 
        while ( ss >> word ) { 
            words.push_back(word);
        } 
        int m = words.size() ; 
        unordered_map<char, string> mp;         
        unordered_map<string, char> mp1;
        int n = pattern.size() ; 
        if ( n != m ) { 
            return false ; 
        }
        for ( int i = 0 ; i < n ; i++ ) { 
            if (mp.find(pattern[i]) == mp.end() ) { 
                mp[pattern[i]] = words[i] ;  
            }
            else { 
                if ( mp[pattern[i]] != words[i] ) { 
                    return false ; 
                }
            }
            if ( mp1.find(words[i]) == mp1.end() ) { 
                mp1[words[i]] = pattern[i] ; 
            }
            else { 
                if ( mp1[words[i]] != pattern[i] ) { 
                    return false ; 
                }
            }
        }
        return true ; 
    }
};