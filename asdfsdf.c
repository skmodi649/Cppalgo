// C program for the travelling salesman problem
#include<stdio.h>
#include<stdlib.h>
 
#define V 4
int completed[10],n,cost=0,value=0;
int ary[][V] = { {0, 25, 10, 15},
             {25, 0, 10, 45},
             {10, 10, 0, 5},
             {15, 45, 5, 0} };
 
void takeInput()
{
    
for(int i = 0 ; i < 10 ; i++)
completed[i]=0;
}

int least(int c)
{
int i,nc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
 
if(min!=999)
cost+=kmin;
 
return nc;
}


 
void mincost(int city)
{
int ncity;
 
completed[city]=1;
ncity=least(city);
value = value + ncity + 1;
if(ncity==999)
{
ncity=0;

cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity);
}
 

int main()
{
takeInput();
int arr[5];
for(int i=0;i<5;i++){
scanf("%d",&arr[i]);}
int sum = 0;
for(int i=0;i<5;i++)
{
    int val1 = arr[i];
    int val2 = arr[i+1];
    int path = ary[val1 - 1][val2 - 1];
    sum = sum + path;
}
mincost(0); //passing 0 because starting vertex
if(sum == value)
printf("True");
else
printf("False");
return 0;
}
