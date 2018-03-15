import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;

public class Main{
    
    private static int numSubarrayBoundedMax(int[] A, int L, int R){
        int i = 0;
        int j = 0;
        int count = 0;
        int ij_max = 0;

        while( i < A.length ){
            j = i;
            ij_max = A[i];
            while( j < A.length ){
                if( ij_max < A[j] ){
                    ij_max = A[j];
                }
                if( ij_max >= L && ij_max <= R ){
                    count++;
                }
                j++;
            }
            if( j < A.length ){
                i = j + 1;
            }else{
                i++;
            }

        }
        return count;
    }

    public static void main(String[] args){
        Scanner file = null;
        try{
            file = new Scanner(new File("input.txt"));
        }catch(FileNotFoundException e){
            System.out.println("file not found!");
        }

        int len = file.nextInt();
        int[] A = new int[len]; 
        for(int i=0; i<len; i++){
            A[i] = file.nextInt();
        }

        int L = file.nextInt();
        int R = file.nextInt();

        int count = numSubarrayBoundedMax(A, L, R);
        System.out.format("%d\n", count);
    
    }

}
