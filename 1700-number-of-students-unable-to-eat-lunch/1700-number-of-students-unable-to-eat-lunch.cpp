class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int top = 0 ; 
        int count = 0 ; 
        int front = 0 ; 
        while ( count != students.size() ) { 
            if ( students[front] == sandwiches[top] ) { 
                students.erase(students.begin()) ; 
                top++ ; 
                count = 0 ; 
            }
            else { 
                int a = students[front] ; 
                students.erase(students.begin()) ; 
                students.push_back(a) ; 
                count++ ; 
            }
        } 
        return students.size() ; 
    }
};