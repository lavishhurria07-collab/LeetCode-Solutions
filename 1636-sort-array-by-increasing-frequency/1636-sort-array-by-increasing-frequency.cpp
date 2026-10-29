class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> map ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            map[nums[i]]++ ; 
        }
        vector <pair<int,int>> ans ; 
        for ( auto x : map ) { 
            int num = x.first ; 
            int freq = x.second ; 
            ans.push_back({num,freq}) ; 
        }
        sort(ans.begin(),ans.end(),[](auto &a,auto &b) { 
            if ( a.second != b.second ) { 
                return a.second < b.second ; 
            } 
            return a.first > b.first ; 
        } ) ; 
        vector <int> answer ; 
        for ( auto x : ans ) { 
            int num = x.first ; 
            int time = x.second ; 
            for ( int i = 0 ; i < time ; i++ ) { 
                answer.push_back(num) ; 
            }
        }
        return answer ; 
    }
};