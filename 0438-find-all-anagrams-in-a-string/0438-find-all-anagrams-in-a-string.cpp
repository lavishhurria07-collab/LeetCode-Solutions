class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans ; 
        int n = s.size() ; 
        int k = p.size() ; 
        int frequency1[26] = {0} ; 
        for ( int i = 0 ; i < k ; i++ ) { 
            frequency1[p[i]-'a']++ ; 
        }
        int frequency2[26] = {0} ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( right < n ) { 
            frequency2[s[right]-'a']++ ; 
            if ( ( right - left + 1 ) > k ) { 
                frequency2[s[left]-'a']-- ; 
                left++ ; 
            } 
            if ( ( right - left + 1 ) == k ) { 
                int m = 0 ; 
                for ( int i = 0 ; i < 26 ; i++ ) { 
                    if ( frequency1[i] != frequency2[i] ) { 
                        m = 1 ; 
                    }
                }
                if ( m == 0 ) { 
                    ans.push_back(left) ; 
                }
            } 
            right++ ; 
        }
        return ans ; 
    }
};