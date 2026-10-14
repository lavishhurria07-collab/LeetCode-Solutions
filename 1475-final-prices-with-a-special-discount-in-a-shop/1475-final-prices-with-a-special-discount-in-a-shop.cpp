class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size() ; 
        vector <int> ans(n,0) ;  
        for ( int i = 0 ; i < n ; i++ ) { 
            ans[i] = prices[i] ; 
        }
        vector <int> stack ; 
        int top = -1 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && prices[stack[top]] >= prices[i] ) { 
                int p = stack[top] ; 
                int price = prices[p] - prices[i] ; 
                ans[p] = price ; 
                stack.pop_back() ; 
                top-- ; 
            }
            top++ ; 
            stack.push_back(i) ; 
        } 
        return ans ; 
    }
};