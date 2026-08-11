class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size() ;
        int start = 0 ; 
        int end = n - 1 ; 
        while ( start < end ) {
            while (start < n &&
       tolower(s[start]) != 'a' &&
       tolower(s[start]) != 'e' &&
       tolower(s[start]) != 'i' &&
       tolower(s[start]) != 'o' &&
       tolower(s[start]) != 'u') {
    start++;
}
            while (end >= 0 &&
       tolower(s[end]) != 'a' &&
       tolower(s[end]) != 'e' &&
       tolower(s[end]) != 'i' &&
       tolower(s[end]) != 'o' &&
       tolower(s[end]) != 'u') {
    end--;
}
            if (start < end) {
    swap(s[start], s[end]);
    start++;
    end--;
}
        }
        return s ;
    }
};