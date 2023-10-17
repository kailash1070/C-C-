#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//  This function does a couple of things
//
//  Copying a string literal to dynamic memory.
//  Reversing the string without extra memory / local variables.

char *reverseSTR(char *arr)
{
    char *p, *q;
    p = arr;
    q = arr;
    int i, n = strlen(arr);
    p = (arr + n - 1);
    n /=2;
    for(i =0; i<n; i++)
    {
        *p = *p + *q;
        *q = *p - *q;
        *p = *p - *q;
        p--;
        q++;
    }
    return arr;
}

int main()
{
    char *p = "hello world";
    printf("Len=%d", strlen(p));
    char *arr = (char *)malloc(strlen(p) * sizeof(char));
    strcpy(arr, p);
    printf("\nReverse str = %s", reverseSTR(arr));
    return 0;
}
