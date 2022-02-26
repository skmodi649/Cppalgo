#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Lab1_10
{
    char username[30] , address[50] , email[30] , pass[30] , con_pass[30] , phone[30];
};
void show(struct Lab1_10 l){
printf("Username : %s\n",l.username);
printf("Address : %s\n",l.address);
printf("Email : %s\n",l.email);
printf("Phone Number : %s\n",l.phone);
}
int main(){
struct Lab1_10 l1 , l2 , l3;
printf("Enter the username , address , email , password , confirm password and phone for the first User : ");
scanf("%s",l1.username);
scanf("%s",l1.address);
scanf("%s",l1.email);
scanf("%s",l1.pass);
scanf("%s",l1.con_pass);
scanf("%s",l1.phone);

printf("Enter the username , address , email , password , confirm password and phone for the Second User : ");
scanf("%s",l2.username);
scanf("%s",l2.address);
scanf("%s",l2.email);
scanf("%s",l2.pass);
scanf("%s",l2.con_pass);
scanf("%s",l2.phone);

printf("Enter the username , address , email , password , confirm password and phone for the Third User : ");
scanf("%s",l3.username);
scanf("%s",l3.address);
scanf("%s",l3.email);
scanf("%s",l3.pass);
scanf("%s",l3.con_pass);
scanf("%s",l3.phone);

char pass1[30] , pass2[30] , pass3[30];
printf("************ First User **************\n");
printf("Enter the password : ");
scanf("%s",pass1);
if(strcmp(l1.pass , pass1) == 0){
    show(l1);
}
else{
    printf("Wrong Password !\n");
}

printf("************ Second User **************\n");
printf("Enter the password : ");
scanf("%s",pass2);
if(strcmp(l2.pass , pass2) == 0){
    show(l2);
}
else{
    printf("Wrong Password !\n");
}

printf("************ Third User **************\n");
printf("Enter the password : ");
scanf("%s",pass3);
if(strcmp(l3.pass , pass3) == 0){
    show(l3);
}
else{
    printf("Wrong Password !\n");
}
return 0;
}