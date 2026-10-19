class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n+1,0) ; 
        // for ( int i = 0 ; i <= n ; i++ ) { 
        //     int count = 0 ; 
        //     int temp = i ; 
        //     while ( temp > 0 ) { 
        //         if ( temp % 2 == 1 ) { 
        //             count++ ; 
        //         }
        //         temp = temp / 2 ; 
        //     }
        //     ans.push_back(count) ; 
        // }
        // return ans ; 
        for ( int i = 1 ; i <= n ; i++ ) { 
            if ( i % 2 == 0 ) { 
                ans[i] = ans[i/2] ; 
            }
            else { 
                ans[i] = ans[i/2] + 1 ; 
            }
        }
        return ans ; 
    }
};