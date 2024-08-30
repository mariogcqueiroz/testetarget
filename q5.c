#include <stdio.h>
#include <string.h>

void inverterString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main()
{
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);

    inverterString(str);
    printf("String invertida: %s\n", str);

    return 0;
}
