#include <stdio.h>
void get(int matrix[][10], int row, int column) {

   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
}

void multiply(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2) {

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}
int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
   printf("Enter the number of rows and columns of the first matrix respectively : ");
   scanf("%d %d", &r1, &c1);
   printf("Enter the number of rows and columns of the second matrix respectively : ");
   scanf("%d %d", &r2, &c2);
   while (c1 != r2) {
      printf("Multiplication not possible because r1 != c2 OR c1 != =r2, Try again!\n");
      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }

   // Get the elements of the first matrix
   get(first, r1, c1);

   // Get the elements of the second matrix
   get(second, r2, c2);

   // Call the multiply() to multiply the two matrices
   multiply(first, second, result, r1, c1, r2, c2);

   // Displaying the resultant matrix
    printf("\nOutput Matrix:\n");
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         printf("%d  ", result[i][j]);
         if (j == c2 - 1)
            printf("\n");
      }
   }

   return 0;
}