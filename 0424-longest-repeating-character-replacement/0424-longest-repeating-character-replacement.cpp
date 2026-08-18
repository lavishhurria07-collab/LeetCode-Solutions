class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char,int> mp ; 
        int n = s.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        int max_length = 0 ; 
        int max_frequency = 0 ; 
        while ( right < n ) {
            mp[s[right]]++ ; 
            max_frequency=max(max_frequency,mp[s[right]]);
            if ( ( right - left + 1  - max_frequency ) > k ) {
                mp[s[left]]--;
                left++;
            }
            if ( ( right - left + 1 ) > max_length ) {
                max_length = right - left + 1 ; 
            }
            right++ ; 
        }
        return max_length ; 
    }
};