class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ; 
        vector <int> ans = {0,0} ;   
        int i = 0 ; 
        int j = n - 1 ; 
        while ( j > i ) { 
            int sum = numbers[i] + numbers[j] ; 
            if ( sum == target ) { 
                ans[0] = i + 1 ; 
                ans[1] = j + 1 ; 
                return ans ; 
            }
            else if ( sum > target ) { 
                j-- ; 
            }
            else { 
                i++ ; 
            }
        }
        return ans ; 
    }
};