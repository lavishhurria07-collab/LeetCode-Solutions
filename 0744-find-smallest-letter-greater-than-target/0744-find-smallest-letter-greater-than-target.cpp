class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0 ; 
        int n = letters.size() ; 
        int end = n - 1 ;
        while ( start < end ) { 
            int mid = start + ( end - start ) / 2 ;
            if (letters[mid]>target) { 
                end = mid ; 
            }
            else if (letters[mid]<=target) { 
                start = mid + 1 ;
            }
        }
        if ( letters[start]<=target) { 
            return letters[0] ;
        }
        else { 
            return letters[start] ;
        }
        return 'a' ;
    }
};