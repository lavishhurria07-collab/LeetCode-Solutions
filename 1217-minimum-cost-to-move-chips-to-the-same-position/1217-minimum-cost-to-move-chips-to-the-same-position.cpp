class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size() ; 
        int odd_count = 0 ; 
        int even_count = 0 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            if ( position[i] % 2 == 0 ) { 
                odd_count++ ; 
            }
            else { 
                even_count++ ; 
            }
        }
        int ans = min(odd_count,even_count) ; 
        return ans ; 
    }
};