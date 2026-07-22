class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==0 || num==1 ){ 
            return true ;
        }
        int start=1;
        int end=num; 
        while (start<=end){ 
            int mid=start+(end-start)/2; 
            if ((num / mid)== mid) {
                if ( num%mid == 0 ){ 
                    return true; 
                }
                else {
                    return false ;
                }
            } 
            else if ( num/mid>mid ) { 
                start=mid+1; 
            }
            else if (num/mid<mid) { 
                end=mid-1;
            }
        }
        return false;
    }
};