class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int a = nums.size() ; 
        vector <int> ans ;
        for ( int i = 0 ; i < a ; i++ ) { 
            int n = nums [ i ] ; 
            int m = nums [ n ] ; 
            ans.push_back ( m ) ;
        }
        return ans ;
    }
};