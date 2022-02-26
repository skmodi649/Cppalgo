#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void operate(char arr[][30] , int size_of_arr){
    char str[30];
    int max = -99999;
    char strmax[30];
    for(int i = 0 ; i < size_of_arr ; i++){
        if(len(arr[i]) > max){
            max = len(arr[i]);
            strmax = arr[i];
        }
        }
        printf("Maximum length Name : %s",strmax);
}
int main(){
    printf("Enter Name , Age , Address and Phone number of the 10 persons respectively");
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