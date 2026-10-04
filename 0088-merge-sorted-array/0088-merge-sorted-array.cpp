class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = nums1.size() ; 
        int k = nums2.size() ; 
        int index1 = m - 1 ; 
        int index2 = k - 1 ;  
        int insert = l - 1 ; 
        while ( index1 >= 0 && index2 >= 0 ) { 
            if ( nums1[index1] > nums2[index2] ) { 
                nums1[insert] = nums1[index1] ; 
                index1-- ; 
            }
            else if ( nums1[index1] <= nums2[index2] ) { 
                nums1[insert] = nums2[index2] ; 
                index2-- ; 
            }
            insert-- ; 
        } 
        while ( index2 >= 0 && insert >= 0 ) { 
            nums1[insert] = nums2[index2] ; 
            index2-- ; 
            insert-- ; 
        }
    }
};