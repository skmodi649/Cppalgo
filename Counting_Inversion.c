#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    printf("Enter the size of the array : \n");
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
     //Since we are creating a dynamic array, we need to allot memory for it
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int inversioncount = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            inversioncount++;
        }
    }
    printf("Number of inversions : %d",inversioncount);
    return 0;
}
