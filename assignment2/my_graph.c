#include <stdio.h>
#include "my_mat.h"

int main(){
    int myMat[10][10];
    int i, j;
    char option;

    while(option != 'D'){
        scanf("%c", &option);
        switch (option)
        {
        case 'A':
            createMatrix(myMat);
            break;
        
        case 'B':
            scanf("%d%d" ,&i, &j);
            isTherePath(myMat, i, j);
            break;
        
        case 'C':
            scanf("%d%d" ,&i, &j);
            shortestPath(myMat, i, j);
            break;
        
        default:
            break;
        }
    }
    return 0;
}