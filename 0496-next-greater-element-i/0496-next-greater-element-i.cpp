class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans ; 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        for ( int i = 0 ; i < nums1.size() ; i++ ) { 
            for ( int j = 0 ; j < nums2.size() ; j++ ) { 
                if ( nums2[j] == nums1[i] ) { 
                    int ptr = j ; 
                    int index = -1 ; 
                    for ( int k = j + 1 ; k < nums2.size() ; k++ ) { 
                        if ( nums2[k] > nums2[ptr] ) { 
                            index = nums2[k] ; 
                            break ;  
                        }
                    }
                    ans.push_back(index) ;                   
                }
            }
        }
        return ans ; 
    }
};