class Solution {
public:
    void all_sum ( vector<int>& candidates , vector<vector<int>> &ans , vector<int> &sum , int target , int index ) { 
        int n = candidates.size() ; 
        if ( target == 0 ) { 
            ans.push_back(sum) ; 
            return ; 
        }
        if ( target < 0 ) { 
            return ; 
        }
        if ( index == n ) { 
            return ; 
        }
        sum.push_back(candidates[index]) ; 
        // single inclusion call . 
        all_sum ( candidates , ans , sum , target - candidates[index] , index ) ;  
        sum.pop_back() ; 
        // exclusion call . 
        all_sum ( candidates , ans , sum , target , index + 1 ) ; 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ; 
        vector<int> sum ; 
        all_sum(candidates,ans,sum,target,0) ; 
        return ans ; 
    }
};