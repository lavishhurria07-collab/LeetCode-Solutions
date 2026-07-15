class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> ans ;
        int n = numbers.size() ;
        int start = 0 ;
        int end = n-1 ;
        while  ( end > start ) { 
            int sum = numbers[start] + numbers[end] ;
            if ( sum == target )  {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans ;
            }
            if ( sum > target ) { 
                end-- ;
            }
            if ( sum < target ) { 
                start++ ;
            }
        }
        return {} ;
    }
};