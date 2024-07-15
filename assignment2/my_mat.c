#include <stdio.h>
#include "my_mat.h"

void printMat(int mat[][10]){
    for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
    }
    printf("\n");            
}

void floydWarshall(int mat[][10]){
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(mat[i][j]>mat[i][k]+mat[k][j]){
                    mat[i][j] = mat[i][k]+mat[k][j];
                }    
            }
        }    
    }

}

void createMatrix(int mat[][10]){
    printf("Enter the matrix values:\n");
    for(int i = 0; i < 10 ;i++){
        for (int j = 0; j < 10; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] == 0 && i != j){
                mat[i][j] = INFINITY;
            }
        }
    }
    printMat(mat);
    floydWarshall(mat);
    printMat(mat);

}         
        
void isTherePath(int mat[][10], int i, int j){
    if(mat[i][j] == INFINITY || mat[i][j] == 0){
        printf("false\n");  
    }
    else{
        printf("true\n");
    }


}       

void shortestPath(int mat[][10], int i, int j){
    if(mat[i][j] == INFINITY || mat[i][j] == 0){
         printf("-1\n"); 
    }     
    else{
        printf("%d\n", mat[i][j]);
    }
    
}

        