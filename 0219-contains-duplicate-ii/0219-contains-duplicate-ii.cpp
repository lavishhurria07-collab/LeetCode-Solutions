class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size() ; 
        unordered_set <int> frequency ; 
        int left = 0 ; 
        int right = 0 ; 
        while ( right < n ) {
            if ( frequency.find(nums[right]) != frequency.end()) {
                if ( ( right - left  ) <= k ) {
                    return true ; 
                }
            }
            else {
                frequency.insert(nums[right]) ; 
            }
            if (( right - left + 1 ) >k ) {
                frequency.erase(nums[left]) ; 
                left++ ; 
            }
            right++ ; 
        }
        return false ; 
    }
};