class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        vector <int> answer ; 
        int max_size = 1 ; 
        int prev = nums[0] ; 
        answer.push_back(nums[0]) ; 
        for ( int i = 1 ; i < nums.size() ; i++ ) { 
            if ( prev < nums[i] ) { 
                answer.push_back(nums[i]) ; 
                prev = nums[i] ; 
                int a = answer.size() ; 
                max_size = max(max_size,a) ; 
            }
            else { 
                answer.clear() ; 
                prev = nums[i] ; 
                answer.push_back(nums[i]) ; 
            }
        }
        vector <int> ans ; 
        int min_size = 1 ; 
        int pr = nums[0] ; 
        ans.push_back(nums[0]) ; 
        for ( int i = 1 ; i < nums.size() ; i++ ) { 
            if ( pr > nums[i] ) { 
                ans.push_back(nums[i]) ; 
                pr = nums[i] ; 
                int a = ans.size() ; 
                max_size = max(max_size,a) ; 
            }
            else { 
                ans.clear() ; 
                pr = nums[i] ; 
                ans.push_back(nums[i]) ; 
            }
        }
        if ( max_size > min_size ) { 
            return max_size ; 
        } 
        else { 
            return min_size ; 
        }
    }
};