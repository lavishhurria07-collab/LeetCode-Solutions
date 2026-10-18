class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.size() ; 
        int m = words.size() ; 
        int count = 0 ; 
        unordered_map <char,int> map ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            map[allowed[i]]++ ; 
        }
        for ( int i = 0 ; i < m ; i++ ) { 
            int m = 0 ; 
            for ( int j = 0 ; j < words[i].size() ; j++ ) { 
                if ( map.find(words[i][j]) == map.end() ) { 
                    m = 1 ; 
                }
            }
            if ( m == 0 ) { 
                count++ ; 
            }
        }
        return count ; 
    }
};