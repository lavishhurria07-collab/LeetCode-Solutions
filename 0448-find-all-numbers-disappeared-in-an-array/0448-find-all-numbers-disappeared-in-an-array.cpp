class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size() ;  
        vector<int> ans ; 
        unordered_map<int,int> frequency ;  
        for ( int i = 0 ; i < n ; i++ ) { 
            frequency[nums[i]]++ ; 
        }
        for ( int i = 1 ; i <= n ; i++ ) { 
            if ( frequency[i] == 0 ) { 
                ans.push_back(i) ; 
            }
        }
        return ans ; 
    }
};