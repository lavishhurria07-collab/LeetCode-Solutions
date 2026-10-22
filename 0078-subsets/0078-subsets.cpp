class Solution {
public: 
    void helper_function ( vector<int>& nums , int i , vector<int> &current , vector<vector<int>> &ans ) { 
        if ( i == nums.size() ) { 
            ans.push_back(current) ; 
            return ; 
        }
        current.push_back(nums[i]) ; 
        helper_function(nums,i+1,current,ans) ; 
        current.pop_back() ; 
        helper_function(nums,i+1,current,ans) ; 
    }
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector <int> current ; 
        vector<vector<int>> ans ; 
        helper_function(nums,0,current,ans) ;
        return ans ; 
    }
};