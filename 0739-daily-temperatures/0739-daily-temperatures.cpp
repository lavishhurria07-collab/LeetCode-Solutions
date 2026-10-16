class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        int n = temperatures.size() ; 
        vector <int> ans(n,0) ; 
        vector <int> stack ; 
        int top = -1 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && temperatures[stack[top]] < temperatures[i] ) { 
                int index = i - stack[top] ; 
                ans[stack[top]] = index ; 
                stack.pop_back() ; 
                top-- ; 
            }
            top++ ; 
            stack.push_back(i) ; 
        } 
        return ans ; 
    }
};