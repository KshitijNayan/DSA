#include <stdio.h>\
//code for character pyramid 

int main()
{
    int n, i, j, k, space;
    char c;
    printf("Enter the height of the pyramid: \n");
    scanf("%d", &n);
    for (i = 0, k = 1; i < n; i++)
    {
        c = 'A';
        for (space = 1; space <= n - i; space++)
            printf(" ");
        for (j = 0; j < 1 + k / 2; j++)
            printf("%c ", c++);
        c = c - 2;
        for (j = 0; j < k / 2; j++)
            printf("%c ", c--);
        k += 2;
        printf("\n");
    }
    return 0;
}