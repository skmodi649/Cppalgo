#include<stdio.h>
#include<stdlib.h>
int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[20];
    printf("Enter elements in the array : ");
    for(int i = 0 ; i < size ; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array after removing the duplicates : ");
    for (int i = 0; i < size; i ++)  
    {  
        for (int j = i + 1; j < size; j++)  
        {  
            // use if statement to check duplicate element  
            if ( arr[i] == arr[j])  
            {  
                // delete the current position of the duplicate element  
                for (int k = j; k < size - 1; k++)  
                {  
                    arr[k] = arr [k + 1];  
                }  
                // decrease the size of array after removing duplicate element  
                size--;  
                  
            // if the position of the elements is changes, don't increase the index j  
                j--;      
            }  
        }  
    } 
      for (int i = 0; i < size; i++)  
    {  
        printf (" %d \t", arr[i]);  
    }  
    return 0;   

}