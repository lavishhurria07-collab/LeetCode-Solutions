class Solution {
public: 
    void all_subsets ( vector <int> &nums , vector <int> &ans , int i , vector<vector<int>> &result ) { 
        if ( i == nums.size() ) { 
            result.push_back(ans) ; 
            return ;     
        }
        ans.push_back(nums[i]) ; 
        all_subsets(nums,ans,i+1,result) ; 
        ans.pop_back( ) ; 
        all_subsets(nums,ans,i+1,result) ;  
    } 
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<vector<int>> result ; 
        vector <int> ans ; 
        all_subsets(nums,ans,0,result) ; 
        return result ; 
    }
};