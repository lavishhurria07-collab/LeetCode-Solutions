class Solution {
public:
    bool isBalanced(string num) {
        int sum1 = 0 ; 
        int sum2 = 0 ; 
        for ( int i = 0 ; i < num.size() ; i = i + 2 ) { 
            int number = num[i] - '0' ; 
            sum1 = sum1 + number ; 
        }
        for ( int i = 1 ; i < num.size() ; i = i + 2 ) { 
            int number = num[i] - '0' ; 
            sum2 = sum2 + number ; 
        }
        if ( sum1 == sum2 ) { 
            return true ; 
        }
        else { 
            return false ; 
        }
    }
};