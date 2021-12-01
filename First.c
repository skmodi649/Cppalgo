// Program to find winner , second winner , loser and second loser in an sports event

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    printf("Enter the number of players in the event : \n");
    scanf("%d",&n);
    printf("Enter the scores of the players : \n");

    //Since we are creating a dynamic array, we need to allot memory for it
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int first = -9999 , second = -9999 , last = 100000 , secondlast = 100000;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > first){
            second = first;
        first = arr[i];}
        else if(second<arr[i] && first>arr[i])
        {
            second = arr[i];
        }
        if(arr[i] < last)
        {
            secondlast = last;
            last = arr[i];
        }
        else if(secondlast>arr[i] && arr[i]!=last)
        {
            secondlast = arr[i];
        }
    }
    printf("Winner : %d\n",first);
    printf("Second winner : %d\n",second);
    printf("Worst Player : %d\n",last);
    printf("Second worst Player : %d\n",secondlast);
    
    return 0;
}
