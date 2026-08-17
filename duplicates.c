#include <stdio.h>

int main()
{
    char str[100], stack[100];
    int top = -1, i;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(top != -1 && stack[top] == str[i])
        {
            top--;
        }
        else
        {
            stack[++top] = str[i];
        }
    }

    printf("String after removing duplicates: ");

    for(i = 0; i <= top; i++)
        printf("%c", stack[i]);

    return 0;
}