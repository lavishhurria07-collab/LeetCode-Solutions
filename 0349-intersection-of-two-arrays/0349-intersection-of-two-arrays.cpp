class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        sort(nums1.begin(),nums1.end()) ; 
        sort(nums2.begin(),nums2.end()) ; 
        vector <int> answer ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            int left = 0 ; 
            int right = m - 1 ; 
            int found = 0 ; 
            while ( left <= right ) { 
                int mid = left + ( right - left ) / 2 ; 
                if ( nums2[mid] == nums1[i] ) { 
                    found = 1 ; 
                    break ;  
                }
                else if ( nums2[mid] > nums1[i] ) { 
                    right = mid - 1 ; 
                }
                else if ( nums2[mid] < nums1[i] ) { 
                    left = mid + 1 ; 
                }
            }
            if ( found == 1 ) { 
                if ( answer.size() != 0 && answer.back() != nums1[i] ) { 
                    answer.push_back(nums1[i]) ; 
                }
                else if ( answer.size() == 0 ) { 
                    answer.push_back(nums1[i]) ; 
                }
            }
        }  
        return answer ;  
    }
};