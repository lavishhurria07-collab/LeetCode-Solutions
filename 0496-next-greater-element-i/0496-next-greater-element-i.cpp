class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums2.size() ; 
        unordered_map <int,int> map ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            map[nums2[i]] = -1 ; 
        }
        vector <int> stack ; 
        int top = -1 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            while ( top != -1 && stack[top] < nums2[i] ) { 
                map[stack[top]] = nums2[i] ; 
                stack.pop_back() ; 
                top-- ; 
            }
            top++ ; 
            stack.push_back(nums2[i]) ; 
        }
        int m = nums1.size() ; 
        vector <int> ans(m,0) ; 
        for ( int i = 0 ; i < nums1.size() ; i++ ) { 
            int a = map[nums1[i]] ; 
            ans[i] = a ; 
        }
        return ans ; 
    }
};