class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int max_profit = INT_MIN ;
        int min = INT_MAX ;
        int n = prices.size() ;
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( prices[i] < min ) { 
                min = prices[i] ;
            }
            int profit = prices[i] - min ;
            if ( profit > max_profit ) { 
                max_profit = profit ;
            }
        }
        if ( max_profit > 0 ) { 
            return max_profit ;
        }
        else { 
            return 0 ;
        }
    }
};