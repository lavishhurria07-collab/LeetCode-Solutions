class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector <int> ans ;
        for ( int i = left ; i <= right ; i++ ) { 
            int temp = i ;
            int num = i ;
            bool result = true ;
            while ( num > 0 ) { 
                int n = num % 10 ;
                if ( n != 0 ) { 
                    if ( temp % n != 0 ) { 
                        result = false ; 
                    }
                }
                else { 
                    result = false ;
                }
                num = num / 10 ;
            }
            if ( result == true ) { 
                ans.push_back(temp) ;
            }
        }
        return ans ;
    }
};