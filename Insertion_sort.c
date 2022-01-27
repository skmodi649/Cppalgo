// Insertion sort implemenation in C

#include <stdio.h>
#include <stdlib.h>
// function to perform the insertion sort operation in the ascending order
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element till a smaller element is found
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Driver code
int main() {
  int data[] = {10, 8, 12, 6, 7, 9, 4, 3, 15, 13, 2, 1, 11, 5, 14};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Sorted Array:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }
}