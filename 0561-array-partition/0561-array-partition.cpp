class Solution {
public:
    int arrayPairSum(vector<int>& nums) { 
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        vector <pair<int,int>> ans ; 
        for ( int i = 0 ; i < n ; i = i + 2 ) { 
            ans.push_back({nums[i],nums[i+1]}) ; 
        } 
        int sum = 0 ; 
        for ( int i = 0 ; i < n/2 ; i++ ) { 
            sum = sum + min(ans[i].first,ans[i].second) ; 
        }
        return sum ; 
    } 
};