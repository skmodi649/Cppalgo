#include<stdio.h>
#include<conio.h>
void MinMaxIterative(int arr[],int n)
{
    int min = arr[0],max = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max = arr[i];
        if(arr[i]<min)
        min = arr[i];
    }
     printf("The maximum number in the array : %d\n",max);
        printf("The minimum number in the array : %d\n",min);
}
    int main()
    {
        int len;
        printf("Enter the length of the array : ");
        scanf("%d",&len);
        int *a;
         //Since we are creating a dynamic array, we need to allot memory for it
        a = (int *)malloc(sizeof(int)*len);
        printf("Enter the numbers in the array : ");
        for(int i=0;i<len;i++)
        {
            scanf("%d",&a[i]);
        }
        MinMaxIterative(a,len);
        return 0;
    }

