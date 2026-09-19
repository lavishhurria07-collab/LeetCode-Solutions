class Solution {
public:
    vector<int> runningSum(vector<int>& nums) { 
        vector<int> run_sum ; 
        int sum = 0 ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            sum = sum + nums[i] ; 
            run_sum.push_back(sum) ; 
        }
        return run_sum ; 
    }
};