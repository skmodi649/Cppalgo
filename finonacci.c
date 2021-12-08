#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int factorial = 1;
if(n==0){
printf("1");}
else{
for(int i=1;i<=n;i++)
factorial = factorial * i;
printf("%d",factorial);}
return 0;
}