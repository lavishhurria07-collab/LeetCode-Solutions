int singleNumber(int* nums, int numsSize) { 
    for ( int i = 0 ; i < numsSize ; i++ ) { 
        int k = 0 ;
        int n = nums [ i ] ;
        for ( int j = 0 ; j < numsSize ; j++ ) { 
            if ( n == nums [ j ] ) { 
                k++ ;
            }
        }
        if ( k == 1 ) {
           return n ;
        }
    }
    return 0 ;
}