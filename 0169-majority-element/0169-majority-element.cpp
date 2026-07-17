class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int ans=nums[0];
        int frequency=0;
        for ( int i = 0 ; i < n ; i++ ) { 
            if (frequency == 0 ) { 
                ans=nums[i];
            }
            if (nums[i]==ans) { 
                frequency++;
            }
            else{
                frequency--;
            }
        }
        return ans;
    }
};