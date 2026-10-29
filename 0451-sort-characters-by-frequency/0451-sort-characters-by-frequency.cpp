class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> map ; 
        for ( int i = 0 ; i < s.size() ; i++ ) { 
            map[s[i]]++ ; 
        } 
        vector<pair<char,int>> ans ; 
        for ( auto x : map ) {  
            int val = x.second ; 
            char value = x.first ; 
            ans.push_back({value,val}) ; 
        }
        sort(ans.begin(),ans.end(),[](auto &a,auto &b) { return a.second>b.second;}) ; 
        string answer ; 
        for ( auto x : ans ) { 
            int time = x.second ; 
            char input = x.first ; 
            for ( int i = 0 ; i < time ; i++ ) { 
                answer.push_back(input) ; 
            }
        }
        return answer ; 
    }
};