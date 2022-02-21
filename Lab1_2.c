#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void display(char array[][30] , int size_of_arr){
  for(int i=0; i<size_of_arr; i++){
    printf("%s ", array[i]);
  }
  printf("\n");
}

int main()
{
    int size_of_arr;
    scanf("%d",&size_of_arr);
    char arr[size_of_arr][30];
    printf("Enter %d Strings: \n", size_of_arr);
  for(int i=0; i<size_of_arr; i++){
    scanf("%s", arr[i]);
  }
   printf("Original array: ");
  display(arr , size_of_arr);

  char temp[30];

  //Sort array using the Buuble Sort algorithm
  for(int i=0; i<size_of_arr; i++){
    for(int j=0; j<size_of_arr-1-i; j++){
      if(strcmp(arr[j], arr[j+1]) > 0){
        //swap array[j] and array[j+1]
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j+1]);
        strcpy(arr[j+1], temp);
      }
    }
  }

  //display the sorted array
  printf("Array sorted in ascending order: ");
  display(arr , size_of_arr);

//Sort array using the Buuble Sort algorithm
  for(int i=0; i<size_of_arr; i++){
    for(int j=0; j<size_of_arr-1-i; j++){
      if(strcmp(arr[j], arr[j+1]) < 0){
        //swap array[j] and array[j+1]
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j+1]);
        strcpy(arr[j+1], temp);
      }
    }
  }
//display the sorted array
  printf("Array sorted in descending order: ");
  display(arr , size_of_arr);
  return 0;
}


