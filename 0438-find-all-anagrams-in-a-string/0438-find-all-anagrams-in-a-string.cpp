class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size() ; 
        int m = p.size() ; 
        vector<int> ans ;
        int frequency_p[26] ={0} ; 
        int frequency_s[26]={0} ;
        if ( m > n ) {
            return {} ; 
        }
        for ( int i = 0 ; i < m ; i++ ) {
            frequency_p[p[i]-'a']++ ; 
        }
        int left = 0 ; 
        for ( int right = 0 ; right < n ; right++ ) {
            frequency_s[s[right]-'a']++;
            if ( ( right - left + 1 ) > m ) {
                frequency_s[s[left]-'a']-- ; 
                left++ ;
            }
            if ( ( right - left + 1 )== m ) {
                bool match = true ; 
                for ( int i = 0 ; i < 26 ; i++ ) {
                    if ( frequency_p[i]!=frequency_s[i]) {
                        match = false ; 
                    }
                }
                if ( match == true ) {
                    ans.push_back(left); 
                }
            }
        }
        return ans ;
    }
};