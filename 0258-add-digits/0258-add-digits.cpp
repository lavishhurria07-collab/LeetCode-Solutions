class Solution {
public:
    int addDigits(int num) {
        int sum = 0 ;
        while ( num > 0 ) { 
            int a = num % 10 ;
            sum = sum + a ;
            num = num / 10 ;
        }
        int sum_digits = 0 ;
        while ( sum > 0 ) { 
            int b = sum % 10 ;
            sum_digits = sum_digits + b ;
            sum = sum / 10 ;
        }
        while (sum_digits > 9 ) { 
            sum = sum_digits ;
            sum_digits = 0 ;
            while ( sum > 0 ) { 
                int b = sum % 10 ;
                sum_digits = sum_digits + b ;
                sum = sum / 10 ;
            }            
        }
        return sum_digits ;
    }
};