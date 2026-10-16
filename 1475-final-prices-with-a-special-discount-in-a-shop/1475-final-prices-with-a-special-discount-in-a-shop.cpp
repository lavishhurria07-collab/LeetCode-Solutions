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
            while ( top != -1 && prices[i] <= prices[stack[top]] ) { 
                int discount = prices[stack[top]] - prices[i] ; 
                ans[stack[top]] = discount ; 
                top-- ; 
                stack.pop_back() ; 
            }
            top++ ; 
            stack.push_back(i) ; 
        }
        return ans ; 
    }
};