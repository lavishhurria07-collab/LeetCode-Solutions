class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp ;
        int n = s.size() ; 
        int left = 0 ; 
        int right= 0 ; 
        int max_length = 0 ; 
        while ( right < n ) {
            mp[s[right]]++ ; 
            while ( mp[s[right]]>1 ) {
                mp[s[left]]-- ;
                left++ ;
            }
            int length= right - left + 1  ; 
            if ( max_length < length ) {
                max_length = length ; 
            }
            right++ ; 
        } 
        return max_length ; 
    }
};