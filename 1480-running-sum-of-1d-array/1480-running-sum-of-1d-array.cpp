class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector <int> runningSum ;
        int s = nums.size() ;
        for ( int j = 0 ; j < s ; j++ ) { 
            int sum = 0 ;
            for ( int i = 0 ; i < j + 1 ; i++ ) { 
                sum = sum + nums [ i ] ;
            }
            runningSum.push_back(sum) ;
        }
        return runningSum ;
    }
};