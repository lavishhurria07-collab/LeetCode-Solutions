class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool result ; 
        int n = arr.size() ; 
        sort(arr.begin(),arr.end()) ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            int target = 2 * arr[i] ; 
            int left = 0 ; 
            int right = n - 1 ; 
            while ( left <= right ) { 
                int mid = left + ( right - left ) / 2 ; 
                if ( arr[mid] == target ) { 
                    if ( i == mid ) { 
                        left = mid + 1 ; 
                    }
                    else { 
                        return true ; 
                    }
                }
                else if ( arr[mid] < target ) { 
                    left = mid + 1 ; 
                } 
                else if ( arr[mid] > target ) { 
                    right = mid - 1 ; 
                } 
            }
        }
        return false ; 
    }
};