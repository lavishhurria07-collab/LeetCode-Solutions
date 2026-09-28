class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size() ; 
        int k = minutes ; // window size . 
        int sum = 0 ; 
        int ans = 0 ; 
        int max_sum = 0 ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( right < n ) { 
            if ( grumpy[right] == 0 ) { 
                ans = ans + customers[right] ; 
            }
            else { 
                sum = sum + customers[right] ; 
            }
            if ( ( right - left + 1 ) > k ) { 
                if ( grumpy[left] == 1 ) { 
                    sum = sum - customers[left] ; 
                }
                left++ ; 
            }
            if ( ( right - left + 1 ) == k ) { 
                max_sum = max(max_sum,sum) ; 
            }
            right++ ; 
        }
        ans = ans + max_sum ; 
        return ans ; 
    } 
};