#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void operate(char arr[][30] , int size_of_arr){
    char str[30];
    int max = -99999;
    int min = 99999;
    char strmax[30] , strmin[30];
    for(int i = 0 ; i < size_of_arr ; i++){
        if(len(arr[i]) > max){
            max = len(arr[i]);
            strmax = arr[i];
        }
        }
        for(int i = 0 ; i < size_of_arr ; i++){
        if(len(arr[i]) < min){
            max = len(arr[i]);
            strmin = arr[i];
        }
        }
        printf("Maximum length word : %s",strmax);
        printf("Minimum length word : %s",strmin);
}
int main(){
     int size_of_arr;
    scanf("%d",&size_of_arr);
    char arr[size_of_arr][30];
    printf("Enter %d Strings: \n", size_of_arr);
  for(int i=0; i<size_of_arr; i++){
    scanf("%s", arr[i]);
  }
  operate(arr , size_of_arr);
  return 0;
}