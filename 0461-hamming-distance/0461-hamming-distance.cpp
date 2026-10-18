class Solution {
public:
    int hammingDistance(int x, int y) {
        // string bin_1 ; 
        // string bin_2 ; 
        // while ( x > 0 ) { 
        //     int a = x % 2 ; 
        //     char ch = ( a + '0' ) ; 
        //     bin_1 = bin_1 + ch ; 
        //     x = x / 2 ; 
        // }
        // reverse(bin_1.begin(),bin_1.end()) ; 
        // while ( y > 0 ) { 
        //     int a = y % 2 ; 
        //     char ch = ( a + '0' ) ; 
        //     bin_2 = bin_2 + ch ; 
        //     y = y / 2 ; 
        // } 
        // reverse(bin_2.begin(),bin_2.end()) ; 
        // int n = bin_1.size() ; 
        // int m = bin_2.size() ; 
        // if ( n > m ) { 
        //     while ( n != m ) { 
        //         bin_2 = "0" + bin_2 ; 
        //         m++ ;  
        //     }
        // }
        // else if ( m > n ) { 
        //     while ( n != m ) { 
        //         bin_1 = "0" + bin_1 ; 
        //         n++ ; 
        //     }
        // }
        // int ans = 0 ; 
        // for ( int i = 0 ; i < n ; i++ ) { 
        //     if ( bin_1[i] ^ bin_2[i] ) { 
        //         ans++ ; 
        //     }
        // }
        // return ans ; 
        int ans = x ^ y ; 
        int bin = 0 ; 
        int count = 0 ; 
        while ( ans > 0 ) { 
            int a = ans % 2 ; 
            if ( a == 1 ) { 
                count++ ; 
            }
            ans = ans / 2 ; 
        } 
        return count ; 
    }
};