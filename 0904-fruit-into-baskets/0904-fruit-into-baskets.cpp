class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        int max_fruits = 0 ; 
        unordered_map <int,int> mp ; 
        while ( right < n ) {
            mp[fruits[right]]++ ;          
            while ( mp.size() > 2 ) {
                    mp[fruits[left]]-- ; 
                    if ( mp[fruits[left]] == 0 ) {
                        mp.erase(fruits[left]) ; 
                    }
                    left++ ; 
            }
            int length= right - left + 1 ; 
            max_fruits = max( max_fruits, length ) ; 
            right++ ; 
        }
        return max_fruits ; 
    }
};