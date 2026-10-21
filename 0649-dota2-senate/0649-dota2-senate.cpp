class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> radient ; 
        queue <int> dire ; 
        for ( int i = 0 ; i < senate.size() ; i++ ) { 
            if ( senate[i] == 'R' ) { 
                radient.push(i) ; 
            }
            else { 
                dire.push(i) ; 
            }
        }
        int n = senate.size() ; 
        while ( !radient.empty() && !dire.empty() ) { 
            if ( radient.front() < dire.front() ) { 
                dire.pop() ;  
                int i = radient.front() + n ; 
                radient.pop() ; 
                radient.push(i) ; 
            }
            else if ( radient.front() > dire.front() ) { 
                radient.pop() ; 
                int i = dire.front() + n ; 
                dire.pop() ; 
                dire.push(i) ; 
            }
        }
        if ( !dire.empty() ) {   
            return "Dire" ; 
        }
        if ( !radient.empty() ) { 
            return "Radiant" ; 
        }
        return "" ; 
    }
};