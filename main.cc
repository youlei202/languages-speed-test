#include <iostream>
#include <fstream>
#include <vector>

int numSubarrayBoundedMax(std::vector<int> &A, int L, int R);

int main(void)
{
    std::vector<int> A;
    int len, L, R, ans;
    std::ifstream file;
    file.open("input.txt");

    file >> len;
    
    for(int i = 0; i<len; i++){
        int x;
        file >> x;
        A.push_back(x);
    }
    file >> L >> R;

    ans = numSubarrayBoundedMax(A, L, R);

    fprintf( stdout, "%d\n", ans );

    return 0;
}


int numSubarrayBoundedMax(std::vector<int> &A, int L, int R)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int ij_max = 0;
    while( i < A.size() ){
        j = i;
        ij_max = A[i];
        while( j < A.size() ){
            if( ij_max < A[j] ){
                ij_max = A[j];
            }
            if( ij_max >= L && ij_max <= R ){
                count++;
            }
            j++;
        }
        if( j < A.size() ){
            i = j + 1; 
        }else{
            i++; 
        }
    
    }
    return count;
}



