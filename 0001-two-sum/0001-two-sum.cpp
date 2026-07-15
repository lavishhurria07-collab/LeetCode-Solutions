class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size() ;
        vector <int> ans ;
        for ( int start = 0 ; start < size ; start++ ) { 
            for ( int end = start + 1 ; end < size ; end++ ) { 
                int sum = 0 ;
                sum = nums[start] + nums[end] ;
                if ( sum == target ) { 
                    ans.push_back(start);
                    ans.push_back(end);
                }
            } 
        }
        return ans ; 
    }
};