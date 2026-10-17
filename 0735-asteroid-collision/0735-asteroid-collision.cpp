class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { 
        int n = asteroids.size() ; 
        vector <int> stack ; 
        int top = -1 ; 
        for ( int i = 0 ; i < n ; i++ ) { 
            int result = true ; 
            while ( top != -1 && stack[top] >= 0 && asteroids[i] < 0 ) { 
                if ( abs(asteroids[i] ) == stack[top] ) { 
                    top-- ; 
                    stack.pop_back() ; 
                    result = false ; 
                    break ; 
                } 
                else if ( abs(asteroids[i]) > stack[top] ) { 
                    top-- ; 
                    stack.pop_back() ; 
                    result = true ; 
                } 
                else { 
                    result = false ; 
                    break ; 
                }
            }
            if ( result == true ) { 
                top++ ; 
                stack.push_back(asteroids[i]) ; 
            }
        }
        return stack ; 
    } 
};