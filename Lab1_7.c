#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n;
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    char name[n][30] , id[n][10] , address[n][50] , phone[n][20];
    for(int i = 0 ; i < n ; i++){
    printf("Enter the employee name : ");
    scanf("%s",name[i]);
    printf("Enter the employee id : ");
    scanf("%s",id[i]);
    printf("Enter the employee address : ");
    scanf("%s",address[i]);
    printf("Enter the employee phone number : ");
    scanf("%s",phone[i]);
    }
    printf("********************* EMPLOYEE DETAILS *************************");
    for(int j = 0 ; j < n ; j++){
        printf("Name : %s\n",name[j]);
        printf("Id : %s\n",id[j]);
        printf("address : %s\n",address);
        printf("phone : %s\n",phone[j]);
    }
}