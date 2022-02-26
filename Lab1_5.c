#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void operate(char arr[][30] , int size_of_arr){
    char str[80];
    int max = strlen(arr[0]);
    int maxi = 0;
    for(int i = 0 ; i < size_of_arr ; i++){
        if(strlen(arr[i]) > max){
            max = strlen(arr[i]);
            maxi = i;
        }
        }
        printf("Maximum length name : %s \n",arr[maxi]);
}
int main(){
    printf("Enter Name , Age , Address and Phone number of the 10 persons respectively : \n");
    char address[50] , phone[30];
    int age;
     int size_of_arr = 10;
    char arr[size_of_arr][30];
  for(int i=0; i < size_of_arr; i++){
    scanf("%s", arr[i]);
    scanf("%d",&age);
    scanf("%s", address);
    scanf("%s", phone);
  }
  operate(arr , size_of_arr);
  return 0;
}