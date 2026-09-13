class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert = ( m + n - 1 ) ; 
        int first = m - 1 ; 
        int second = n - 1 ; 
        while ( first >= 0 && second >= 0 ) { 
            if ( nums1[first] >= nums2[second] ) { 
                nums1[insert] = nums1[first] ; 
                first-- ; 
            }
            else { 
                nums1[insert] = nums2[second] ; 
                second-- ;
            }
            insert-- ; 
        }
        while ( first >= 0 ) { 
            nums1[insert] = nums1[first] ; 
            first-- ; 
            insert-- ; 
        }
        while ( second >= 0 ) { 
            nums1[insert] = nums2[second] ; 
            second-- ; 
            insert-- ; 
        }
    }
};