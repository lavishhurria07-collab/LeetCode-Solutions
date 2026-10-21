class Solution {
public:
    int findTheWinner(int n, int k) {
        queue <int> ans ; 
        ans.push(1) ; 
        for ( int i = 2 ; i <= n ; i++ ) { 
            ans.push(i) ; 
        }
        while ( ans.size() != 1 ) { 
            for ( int i = 1 ; i < k ; i++ ) { 
                int j = ans.front() ; 
                ans.pop() ; 
                ans.push(j) ; 
            }
            ans.pop() ;  
        }
        return ans.front() ; 
    }
};