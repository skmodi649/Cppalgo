#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char username[30] , pass[30] , con_pass[30] , secret_question[80] , secret_answer[20] , phone[30];
    printf("******************* USER REGISTRATION **********************\n");
    printf("Enter the username : ");
    scanf("%s",username);
    printf("Enter the password : ");
    scanf("%s",pass);
    printf("Enter the password again : ");
    scanf("%s",con_pass);
    printf("Enter the secret question : ");
    scanf("%s",secret_question);
    printf("Enter the secret answer : ");
    scanf("%s",secret_answer);
    printf("Enter the phone number : ");
    scanf("%s",phone);
    char loginuser[30] , loginpass[30];
    printf("******************* USER LOGIN **********************\n");
    printf("Enter the username : ");
    scanf("%s",loginuser);
    printf("Enter the password : ");
    scanf("%s",loginpass);
    if(strcmp(pass , loginpass) == 0){
         printf("LOGIN SUCCESSFUL!\n");
        printf("Username : %s\n",username);
        printf("Phone number : %s",phone);
    }
    else{
        printf("Password Invalid!");
    }
    return 0;
}