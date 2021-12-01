#include<stdio.h>
struct pair
{
int min;
int max;
};

struct pair MinMaxDaC(int arr[], int low, int high)
{
struct pair minmax, mml, mmr;	
int mid;

if (low == high)
{
	minmax.max = arr[low];
	minmax.min = arr[low];	
	return minmax;
}

/* If there are two elements */
if (high == low + 1)
{
	if (arr[low] > arr[high])
	{
		minmax.max = arr[low];
		minmax.min = arr[high];
	}
	else
	{
		minmax.max = arr[high];
		minmax.min = arr[low];
	}
	return minmax;
}

/* If there are more than 2 elements */
mid = (low + high)/2;
mml = MinMaxDaC(arr, low, mid);
mmr = MinMaxDaC(arr, mid+1, high);

/* compare minimums of two parts*/
if (mml.min < mmr.min)
	minmax.min = mml.min;
else
	minmax.min = mmr.min;	

/* compare maximums of two parts*/
if (mml.max > mmr.max)
	minmax.max = mml.max;
else
	minmax.max = mmr.max;	

return minmax;
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
        struct pair minmax = MinMaxDaC(a, 0, len-1);
printf("Minimum element is %d\n", minmax.min);
printf("Maximum element is %d\n", minmax.max);
        return 0;
    }

