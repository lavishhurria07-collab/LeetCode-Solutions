class Solution {
public:
    void all_sum ( vector <int> &candidates , vector <int> &sum , vector<vector<int>> &ans , int n , int k , int index ) { 
        if ( sum.size() == k && n == 0 ) { 
            ans.push_back(sum) ; 
            return ; 
        }
        if ( sum.size() == k && n != 0 ) { 
            return ; 
        } 
        if ( n < 0 || sum.size() > k ) { 
            return ; 
        }
        if ( index == candidates.size() ) { 
            return ; 
        }
        sum.push_back(candidates[index]) ; 
        all_sum ( candidates , sum , ans , n - candidates[index] , k , index + 1 ) ;
        sum.pop_back() ; 
        all_sum ( candidates , sum , ans , n , k , index + 1 ) ; 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> candidates = {1,2,3,4,5,6,7,8,9} ; 
        vector <int> sum ;
        vector<vector<int>> ans ; 
        all_sum ( candidates , sum , ans , n , k , 0 )  ; 
        return ans ; 
    }
};