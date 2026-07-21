class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        vector <int> prefix ;
        vector <int> sufix(n) ;
        prefix.push_back(1);
        for ( int i = 1 ; i < n ; i++ ) {
            int b = prefix[i-1]*nums[i-1];
            prefix.push_back(b);
        }
        sufix[n-1]=1;
        for ( int j = n-2 ; j>=0 ; j--) {
            sufix[j]=sufix[j+1]*nums[j+1];
        }
        for ( int i=0;i<n;i++){
            int a = prefix[i]*sufix[i];
            ans.push_back(a);
        }
        return ans ;
    }
};