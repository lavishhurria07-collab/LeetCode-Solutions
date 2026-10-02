class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ; 
        for ( int i = 0 ; i < n - 1 ; i++ ) { 
            int element = INT_MIN ; 
            for ( int j = i + 1 ; j < n ; j++ ) { 
                if ( arr[j] > element ) { 
                    element = arr[j] ; 
                }
            }
            arr[i] = element ; 
        }
        arr[n-1] = -1 ; 
        return arr ; 
    }
};