#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str1[] = "impeccable";
    // Reversing without using the reverse function
    int len = strlen(str1);
    for(int i = len - 1 ; i >= 0 ; i--){
        printf("%c\n",str1[i]);
    }
    // Reversing the string using a reverse function
    printf("String after reversing : %s",strrev(str1));
    return 0;
}