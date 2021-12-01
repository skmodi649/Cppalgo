#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array : \n");
    int *arr;
    scanf("%d",&n);
    printf("Enter the elements in the array : \n");
     //Since we are creating a dynamic array, we need to allot memory for it
    arr = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int min = arr[0],k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        min = arr[i];
    }
    if(min!=arr[n-1]){
    printf("k does not exist");}
    else{
        int max = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>max){
            max = arr[j];
            k = j;}
        }
        printf("Index : %d",k);
    }
    return 0;
}
