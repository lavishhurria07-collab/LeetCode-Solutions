class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map <int,int> frequency ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[nums[i]]++ ; 
        } 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( frequency[nums[i]] > 1 ) { 
                return true ; 
            }
        }
        return false ; 
    }
};