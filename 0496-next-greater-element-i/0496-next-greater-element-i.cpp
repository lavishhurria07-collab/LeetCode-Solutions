class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        vector <int> ans(n,-1) ; 
        vector <int> stack ; 
        int top = -1 ; 
        unordered_map <int,int> map ; 
        for ( int i = 0 ; i < m ; i++ ) { 
            while ( top != -1 && nums2[stack[top]] < nums2[i] ) { 
                map[nums2[stack[top]]] = nums2[i] ;  
                stack.pop_back() ; 
                top-- ; 
            }
            top++ ;
            stack.push_back(i) ; 
        }
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( map.find(nums1[i]) == map.end() ) { 
                ans[i] = -1 ; 
            }
            else {
                ans[i] = map[nums1[i]] ;
            } 
        }
        return ans ; 
    }
};