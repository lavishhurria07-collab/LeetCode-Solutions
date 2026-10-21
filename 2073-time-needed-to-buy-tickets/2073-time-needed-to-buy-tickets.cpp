class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0 ;  
        while ( tickets[k] != 0 ) { 
            int a = tickets[0] - 1 ; 
            tickets.erase(tickets.begin()) ; 
            if ( a != 0 ) { 
                tickets.push_back(a) ;
            } 
            if ( k > 0 ) { 
                k-- ; 
            }
            else if ( k == 0 && a == 0 ) { 
                return count + 1 ; 
            }
            else if ( k == 0 && a != 0 ) { 
                k = tickets.size() - 1 ; 
            }
            count++ ; 
        }
        return count ; 
    }
};