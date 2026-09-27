class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ; 
        int max_len = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        int count = 0 ; 
        vector<int> frequency (n,0) ;  
        while ( right < n ) { 
            if ( frequency[fruits[right]] == 0 ) { 
                count++ ; 
            }
            frequency[fruits[right]]++ ; 
            while ( count > 2 ) {  
                frequency[fruits[left]]-- ; 
                if ( frequency[fruits[left]] == 0 ) { 
                    count-- ;
                }
                left++ ; 
            }
            int size = right - left + 1 ; 
            max_len = max(max_len,size) ; 
            right++ ; 
        } 
        return max_len ; 
    }
};