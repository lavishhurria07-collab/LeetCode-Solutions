class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( word[right] != ch && right < n ) { 
            right++ ; 
        }  
        if ( right == n ) { 
            return word ; 
        }
        while ( left < right ) { 
            swap(word[left],word[right]) ; 
            left++ ; 
            right-- ; 
        }
        return word ; 
    }
};