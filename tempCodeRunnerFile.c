#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[5];
    for(int i = 0 ; i < 5 ; i++)
    scanf("%d",&arr[i]);

    int target;
    scanf("%d",&target);

    int sol[5];
    for(int i = 0 ; i < 5 ; i++)
    scanf("%d",&arr[i]);

    int sum = 0;
    for(int i = 0 ; i < 5 ; i++)
    {
        if(sol[i] == 1)
        sum = sum + arr[i];
        else
        sum = sum + 0;
    }

    if(sum == target)
    printf("True");
    else
    printf("False");
    return 0;
}