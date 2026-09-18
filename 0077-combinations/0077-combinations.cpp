class Solution {
public: 
    void all_com ( vector<vector<int>> &ans , vector<int> &sum , int k , int n , int index ) { 
        if ( sum.size() == k ) { 
            ans.push_back(sum) ; 
            return ; 
        }
        for ( int i = index ; i <= n ; i++ ) { 
            sum.push_back(i) ; 
            all_com ( ans , sum , k , n , i + 1 ) ; 
            sum.pop_back() ; 
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;  
        vector<int> sum ; 
        all_com ( ans , sum , k , n , 1 ) ;
        return ans ; 
    }
};