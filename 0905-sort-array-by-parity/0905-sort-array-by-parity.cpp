class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) { 
        sort(nums.begin(),nums.end()) ; 
        int n = nums.size() ; 
        int left = 0 ; 
        int right = n - 1 ; 
        while ( left < right ) { 
            while ( nums[right] % 2 != 0 && left < right ) { 
                right-- ; 
            }
            while ( nums[left] % 2 != 1 && left < right ) { 
                left++ ; 
            }
            swap(nums[left],nums[right]) ; 
            left++ ; 
            right-- ; 
        }
        return nums ; 
    }
};