class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int left = 0 ; 
        int right = 0 ; 
        long long max_sum = 0 ; 
        long long sum = 0 ; 
        unordered_map <int,int> frequency ; 
        int distinct = 0 ; 
        while ( right < n ) { 
            sum = sum + nums[right] ; 
            frequency[nums[right]]++ ;  
            if ( frequency[nums[right]] == 1 ) { 
                distinct++ ; 
            }
            if ( ( right - left + 1 ) > k ) { 
                sum = sum - nums[left] ; 
                frequency[nums[left]]-- ; 
                if ( frequency[nums[left]] == 0 ) { 
                    distinct-- ; 
                }
                left++ ; 
            }
            if ( ( right - left + 1 ) == k ) { 
                if ( distinct == k ) { 
                    max_sum = max(max_sum,sum) ; 
                } 
            }
            right++ ; 
        }
        return max_sum ; 
    }
};