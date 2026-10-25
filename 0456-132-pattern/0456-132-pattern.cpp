class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size() ; 
        stack <int> answer ; 
        int s2 = INT_MIN ; 
        for ( int i = n - 1 ; i >= 0 ; i-- ) { 
            if ( nums[i] < s2 ) { 
                return true ; 
            }
            else if ( answer.size() != 0 && answer.top() < nums[i] ) { 
                while ( answer.size() != 0 && answer.top() < nums[i] ) { 
                    s2 = answer.top() ;
                    answer.pop() ; 
                }  
            }
            answer.push(nums[i]) ; 
        }
        return false ; 
    }
};