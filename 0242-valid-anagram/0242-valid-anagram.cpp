class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size() ; 
        int m = t.size() ; 
        if ( m != n ) { 
            return false ; 
        } 
        int left = 0 ;  
        sort(s.begin(),s.end()) ; 
        sort(t.begin(),t.end()) ; 
        while ( left < n ) { 
            if ( s[left] != t[left] ) { 
                return false ; 
            }
            left++ ; 
        }
        return true ; 
    }
};