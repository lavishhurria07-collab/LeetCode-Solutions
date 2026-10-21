class RecentCounter {
private : 
    queue <int> ans ; 
public :
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ans.push(t) ; 
        int starting_range = t - 3000 ; 
        while  ( ans.front() < starting_range ) { 
            ans.pop() ; 
        }
        return ans.size() ; 
    } 
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */