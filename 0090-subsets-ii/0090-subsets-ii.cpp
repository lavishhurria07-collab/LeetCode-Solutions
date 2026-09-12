class Solution {
public:
    void all_subsets ( vector <int> &nums , vector <int> &ans , vector<vector<int>> &result , int i ) { 
        if ( i == nums.size() ) { 
            result.push_back(ans) ; 
            return; 
        }
        ans.push_back(nums[i]) ; 
        all_subsets ( nums , ans , result , i + 1 ) ; 
        ans.pop_back() ; 
        int index = i + 1 ; 
        while ( index < nums.size() && nums[index] == nums[index-1] ) { 
            index = index + 1 ; 
        }
        all_subsets ( nums , ans , result , index ) ; 
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        sort(nums.begin(),nums.end()) ; 
        vector<vector<int>> result ; 
        vector <int> ans ; 
        all_subsets ( nums , ans , result , 0 ) ; 
        return result ;
    }
};