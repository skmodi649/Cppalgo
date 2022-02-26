#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int arr[5][5];
    for(int i = 0 ; i < 5 ; i++){
        int k = i + 1;
        printf("Enter the rainfall data of month %d : ",k);
        for(int j = 0 ; j < 5 ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int a = 0 ; a < 5 ; a++){
        int k = a + 1;
        int sum = 0;
        printf("Average rainfall of month %d : ",k);
        for(int b = 0 ; b < 5 ; b++){
            sum = sum + arr[a][b];
        }
        double average = sum / 5;
        printf("%f\n",average);
    }
    return 0;
}