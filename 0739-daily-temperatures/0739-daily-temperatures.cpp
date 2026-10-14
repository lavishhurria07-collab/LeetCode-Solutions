class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        vector <int> stack ; 
        int top = -1 ; 
        int n = temperatures.size() ; 
        vector <int> ans(n,0) ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && temperatures[stack[top]] < temperatures[i] ) { 
                int a = stack[top] ; 
                int b = i - a ; 
                ans[stack[top]] = b ;
                stack.pop_back() ;  
                top-- ; 
            }
            top++ ; 
            stack.push_back(i) ; 
        }
        return ans ; 
    }
};