class Solution {
public: 
    void permutations ( vector <int> &nums , vector<vector<int>> &result , int index ) { 
        if ( index == nums.size() ) { 
            result.push_back(nums) ; 
            return ; 
        }
        for ( int i = index ; i < nums.size() ; i++ ) { 
            swap(nums[i],nums[index]) ; 
            permutations(nums,result,index+1) ; // recursion for going in forward direction . 
            swap(nums[i],nums[index]) ; // backtracking step . 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result ; 
        permutations(nums,result,0) ; 
        return result ; 
    }
};