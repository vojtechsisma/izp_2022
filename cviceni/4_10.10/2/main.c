#include <stdio.h>

// hledá první výskyt znaku v řetězci, vrací -1,pokud se znak v řetězci nevyskytuje
int my_strchr(char str[], char ch);
int my_abs(int x);

int main()
{
    char input[101], character;
    scanf("%100s %c", input, &character);
    printf("%d\n", my_strchr(input, character));
    return 0;
}

int my_strchr(char str[], char ch)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            return i;
        }
        i++;
    }
    return -1;
}