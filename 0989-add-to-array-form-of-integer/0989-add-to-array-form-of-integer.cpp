class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0 ; 
        vector<int> ans ; 
        int n = num.size() ; 
        int i = n - 1 ; 
        while ( i >= 0 || k > 0 || carry > 0 ) { 
            int m ; 
            if ( k > 0 ) { 
                m = k % 10 ;
            } 
            else { 
                m = 0 ; 
            }
            int h ; 
            if ( i <= -1 ) { 
                h = 0 ; 
            }
            else { 
                h = num[i] ; 
            }
            int number = ( m + h + carry ) % 10 ; 
            ans.push_back(number) ; 
            carry = ( m + h + carry ) / 10 ; 
            i-- ; 
            k = k / 10 ; 
        } 
        reverse(ans.begin(),ans.end()) ; 
        return ans ; 
    }
};