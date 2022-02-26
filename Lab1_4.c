#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void operate(char arr[][80] , int size_of_arr){
    char str[80];
    int max = -99999;
    int min = 99999;
    int maxi = 0 , mini = 0;
    for(int i = 0 ; i < size_of_arr ; i++){
        if(strlen(arr[i]) > max){
            max = strlen(arr[i]);
            maxi = i;
        }
        }
        for(int i = 0 ; i < size_of_arr ; i++){
        if(strlen(arr[i]) < min){
            max = strlen(arr[i]);
            mini = i;
        }
        }
        printf("Maximum length word : %s \n",arr[maxi]);
        printf("Minimum length word : %s",arr[mini]);
}
int main(){
     int size_of_arr;
    scanf("%d",&size_of_arr);
    char arr[size_of_arr][80];
    printf("Enter %d Strings: \n", size_of_arr);
  for(int i=0; i<size_of_arr; i++){
    scanf("%s", arr[i]);
  }
  operate(arr , size_of_arr);
  return 0;
}