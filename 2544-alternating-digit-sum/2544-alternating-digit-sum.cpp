class Solution {
public:
    int alternateDigitSum(int n) {
        vector <int> digits ; 
        while ( n > 0 ) { 
            int a = n % 10 ; 
            digits.push_back(a) ;
            n = n / 10 ;
        } 
        int sum = 0 ;
        int size = digits.size() ;
        for ( int i = size-1 ; i >= 0 ; i=i-2 ) { 
            sum = sum + digits[i] ; 
        }   
        for ( int i = size-2 ; i >= 0 ; i=i-2 ) { 
            sum = sum - digits[i] ; 
        }   
        return sum ;
    }
};