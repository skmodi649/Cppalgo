#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int search(char arr[][30] , int size_of_arr){
    char str[30];
    printf("Enter the word :\n");
    scanf("%s",str);
    for(int i = 0 ; i < size_of_arr ; i++){
        if(strcmp(arr[i], str) == 0){
            return 1;
        }
    }
    return 0;
}
int main(){
     int size_of_arr;
    scanf("%d",&size_of_arr);
    char arr[size_of_arr][30];
    printf("Enter %d Strings: \n", size_of_arr);
  for(int i=0; i<size_of_arr; i++){
    scanf("%s", arr[i]);
  }
  int val = search(arr , size_of_arr);
  if(val == 1){
      printf("Word found in the array\n");
  }
  else{
      printf("Word not found in the array\n");
  }
  return 0;
}