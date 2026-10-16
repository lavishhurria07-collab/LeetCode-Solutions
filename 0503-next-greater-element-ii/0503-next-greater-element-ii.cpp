class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n = nums.size() ; 
        vector <int> ans(n,-1) ; 
        int top = -1 ; 
        vector <int> stack ; 
        for ( int i = 0 ; i < 2 * n ; i++ ) { 
            int index = i % n ; 
            while ( top != -1 && nums[stack[top]] < nums[index] ) { 
                ans[stack[top]] = nums[index] ; 
                top-- ; 
                stack.pop_back() ; 
            }
            top++ ; 
            stack.push_back(index) ; 
        } 
        return ans ; 
    }
};