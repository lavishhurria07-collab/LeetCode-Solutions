class Solution {
public:
    void string_divide ( string &a , int k , vector<string> &st ) { 
        string ch ; 
        for ( int i = 0 ; i < a.size() ; i++ ) { 
            if ( ch.size() == k ) { 
                st.push_back(ch) ; 
                ch.clear() ; 
            }
            ch = ch + a[i] ; 
        }
        st.push_back(ch) ;
        a.clear() ; 
        for ( int i = 0 ; i < st.size() ; i++ ) { 
            int sum = 0 ; 
            for ( int j = 0 ; j < st[i].size() ; j++ ) { 
                int s = st[i][j] - '0' ; 
                sum = sum + s ; 
            }
            string n = to_string(sum) ; 
            a = a + n ; 
        }
    }
    string digitSum(string s, int k) { 
        while ( s.size() > k ) { 
            vector<string> st ; 
            string_divide(s,k,st) ; 
        }
        return s ; 
    }
};