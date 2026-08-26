class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        vector<pair<int,int>> ans ; 
        int n = nums.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            ans.push_back({nums[i],i}) ; 
        }
        sort(ans.begin(),ans.end()) ; 
        vector <int> answer ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left < right ) { 
            int sum = ans[left].first + ans[right].first ; 
            if ( sum == target ) { 
                answer.push_back(ans[left].second) ; 
                answer.push_back(ans[right].second) ;
                return answer ; 
            } 
            else if ( sum > target ) { 
                right-- ; 
            }
            else { 
                left++ ; 
            }
        }
        return answer ; 
    } 
};