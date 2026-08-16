class Solution {
public:
    string frequencySort(string s) {
        int n = s.size() ; 
        string ans = "" ; 
        unordered_map<char,int>mp ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            mp[s[i]]++ ; 
        }
        vector<pair<char,int>> v ;  
        for ( auto x : mp ) { 
            v.push_back(x) ; 
        }
        sort(v.begin(), v.end(), [](auto a, auto b) { return a.second > b.second; }); 
        for ( auto x : v ) { 
            int a = x.second ; 
            char ch = x.first ; 
            for ( int j = 0 ; j < a ; j++ ) { 
                ans += ch ; 
            }
        }
        return ans ; 
    }
};