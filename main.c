#include <stdio.h>
#include <stdlib.h>

int numSubarrayBoundedMax(int *A, int len, int L, int R);

int main(void)
{
    int A[100000];
    int len, L, R, ans;
    FILE *file; 
    
    file = fopen("input.txt", "r");
    fscanf( file, "%d", &len );
    for(int i = 0; i<len; i++){
        fscanf( file, "%d", &A[i] );
    }
    fscanf( file, "%d%d", &L, &R );

    ans = numSubarrayBoundedMax( A, len, L, R );

    fprintf( stdout, "%d\n", ans );

    return 0;
}


int numSubarrayBoundedMax(int *A, int len, int L, int R)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int ij_max = 0;
    while( i < len ){
        j = i;
        ij_max = A[i];
        while( j < len ){
            if( ij_max < A[j] ){
                ij_max = A[j];
            }
            if( ij_max >= L && ij_max <= R ){
                count++;
            }
            j++;
        }
        if( j <len ){
            i = j + 1; 
        }else{
            i++; 
        }
    
    }
    return count;
}
