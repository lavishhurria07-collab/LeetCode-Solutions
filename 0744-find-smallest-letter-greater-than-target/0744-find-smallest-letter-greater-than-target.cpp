class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) { 
        int left = 0 ; 
        int right = letters.size() - 1 ; 
        char answer = '{' ; 
        while ( left <= right ) { 
            int mid = left + ( right - left ) / 2 ; 
            if ( letters[mid] < target ) { 
                left = mid + 1 ; 
            } 
            else if ( letters[mid] > target ) { 
                if ( answer > letters[mid] ) { 
                    answer = letters[mid] ; 
                }
                right = mid - 1 ; 
            } 
            else { 
                left = mid + 1 ; 
            }
        }
        if ( answer == '{' ) { 
            return letters[0] ; 
        }
        return answer ; 
    }
};