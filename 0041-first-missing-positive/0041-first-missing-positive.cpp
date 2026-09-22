class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int range = *max_element(nums.begin(),nums.end()) ; 
        // sort(nums.begin(),nums.end()) ; 
        // int var = 1 ; 
        // for ( int i = 0 ; i < nums.size() ; i++ ) { 
        //     if ( nums[i] == var ) { 
        //         var++ ; 
        //     }
        // }
        // return var ; 
        unordered_map <int,int> map ; 
        for ( int i = 0 ; i < nums.size() ; i++ ) { 
            if ( nums[i] >= 1 ) { 
                map[nums[i]]++ ; 
            }
        }
        int range = *max_element(nums.begin(),nums.end()) ;
        for ( int i = 1 ; i < range ; i++ ) { 
            if (map.find(i) == map.end()) { 
                return i ; 
            }
        }
        if ( range < 0 ) { 
            return 1 ; 
        }
        return (range + 1) ; 
    }
};