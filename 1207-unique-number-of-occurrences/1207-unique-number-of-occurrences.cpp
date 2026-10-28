class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> ans ; 
        int n = arr.size() ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            ans[arr[i]]++ ; 
        }
        vector <int> answer ; 
        for ( auto i : ans ) { 
            int value = i.second ;  
            int key = i.first ; 
            if ( find(answer.begin(),answer.end(),value) == answer.end() ) { 
                answer.push_back(value) ; 
            }
            else { 
                return false ; 
            }
        }
        return true ; 
    }
};