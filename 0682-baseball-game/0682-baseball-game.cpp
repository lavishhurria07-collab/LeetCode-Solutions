class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack ; 
        int top = -1 ; 
        int sum = 0 ; 
        for ( int i = 0 ; i < operations.size() ; i++ ) { 
            if ( operations[i] != "+" && operations[i] != "C" && operations[i] != "D" ) { 
                top++ ; 
                stack.push_back(stoi(operations[i])) ; 
            }
            else if ( operations[i] == "+" ) { 
                int a = stack[top] ; 
                int b = stack[top-1] ; 
                int c = a + b ; 
                top++ ; 
                stack.push_back(c) ; 
            }
            else if ( operations[i] == "D" ) { 
                int a = stack[top] * 2 ; 
                top++ ; 
                stack.push_back(a) ; 
            }
            else if ( operations[i] == "C" ) { 
                stack.pop_back() ; 
                top-- ; 
            }
        }
        while ( top != -1 ) { 
            sum = sum + stack[top] ; 
            top-- ; 
        }
        return sum ; 
    }
};