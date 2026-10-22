class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        vector <int> ans(n,-1) ; 
        vector <int> stack ; 
        unordered_map <int,int> answer ; 
        int top = -1 ; 
        for ( int i = 0 ; i < m ; i++ ) { 
            while ( top != -1 && stack[top] < nums2[i] ) { 
                answer[stack[top]] = nums2[i] ; 
                stack.pop_back() ; 
                top-- ; 
            }
            top++ ; 
            stack.push_back(nums2[i]) ; 
        }
        for ( int i = 0 ; i < n ; i++ ) {  
            if ( answer.find(nums1[i]) == answer.end() ) { 
                ans[i] = -1 ; 
            }
            else { 
                ans[i] = answer[nums1[i]] ; 
            }
        }
        return ans ; 
    }
};