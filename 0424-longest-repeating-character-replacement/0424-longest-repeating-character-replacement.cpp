class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() ; 
        int right = 0 ; 
        int left = 0 ; 
        // window valid condition => window size - max frequency element <= k . 
        int frequency[26] = {0} ; 
        int max_frequency = 0 ; 
        int max_len = 0 ; 
        while ( right < n ) { 
            frequency[s[right]-'A']++ ; 
            max_frequency = max(max_frequency,frequency[s[right]-'A']) ; 
            if ( ( right - left + 1 ) - max_frequency > k ) { 
                while ( ( right - left + 1 ) - max_frequency > k ) { 
                    frequency[s[left]-'A']-- ; 
                    left++ ; 
                }
            } 
            max_len = max(max_len,(right - left + 1)) ; 
            right++ ; 
        } 
        return max_len ; 
    }
};