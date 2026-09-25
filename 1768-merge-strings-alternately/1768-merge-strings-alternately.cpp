class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int pointer1 = 0 ; 
        int pointer2 = 0 ; 
        string ans ; 
        int n = word1.size() ; 
        int m = word2.size() ; 
        while ( pointer1 < n && pointer2 < m ) { 
            ans = ans + word1[pointer1] + word2[pointer2] ; 
            pointer1++ ; 
            pointer2++ ; 
        }
        while ( pointer1 < n ) { 
            ans = ans + word1[pointer1] ; 
            pointer1++ ; 
        }
        while ( pointer2 < m ) { 
            ans = ans + word2[pointer2] ; 
            pointer2++ ; 
        }
        return ans ; 
    }
};