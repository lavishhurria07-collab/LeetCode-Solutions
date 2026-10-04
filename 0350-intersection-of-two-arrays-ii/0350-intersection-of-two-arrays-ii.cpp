class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ; 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        sort(nums1.begin(),nums1.end()) ; 
        sort(nums2.begin(),nums2.end()) ; 
        int index1 = 0 ; 
        int index2 = 0 ; 
        while ( index1 < n && index2 < m ) { 
            if ( nums1[index1] > nums2[index2] ) { 
                index2++ ; 
            }
            else if ( nums1[index1] < nums2[index2] ) { 
                index1++ ; 
            }
            while ( index1 < n && index2 < m && nums1[index1] == nums2[index2] ) { 
                ans.push_back(nums1[index1]) ; 
                index1++ ; 
                index2++ ; 
            }
        }
        return ans ; 
    }
};