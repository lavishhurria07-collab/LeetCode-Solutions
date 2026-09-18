class Solution {
public:
    void all_sum ( vector<int>& candidates , vector<int>& sum , vector<vector<int>>& ans , int target , int index ) { 
        if ( target == 0 ) { 
            ans.push_back(sum) ; 
            return ; 
        }
        if ( target < 0 ) { 
            return ; 
        }
        for ( int i = index ; i < candidates.size() ; i++ ) { 
            if ( i > index && candidates[i] == candidates[i-1] ) { 
                continue ; 
            }
            sum.push_back(candidates[i]) ; 
            all_sum ( candidates , sum , ans , target - candidates[i] , i + 1 ) ; 
            sum.pop_back() ; 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin() , candidates.end()) ; 
        vector<int> sum ; 
        vector<vector<int>> ans ; 
        all_sum ( candidates , sum , ans , target , 0 ) ; 
        return ans ; 
    }
};