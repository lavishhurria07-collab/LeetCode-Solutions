class Solution {
public:
    bool isHappy(int n) {
        int result = false ; 
        unordered_set <int> ans ; 
        int sum ; 
        int temp = n ; 
        int m ; 
        while ( true ) { 
            sum = 0 ;  
            while ( temp > 0 ) { 
                sum = sum + ( temp % 10 ) * ( temp % 10 ) ; 
                temp = temp / 10 ; 
            }
            if ( ans.find(sum) == ans.end() ) { 
                ans.insert(sum) ; 
            }
            else { 
                return false ; 
            }
            if ( sum == 1 ) { 
                return true ;  
            }
            temp = sum ; 
        }
        return true ; 
    }
};