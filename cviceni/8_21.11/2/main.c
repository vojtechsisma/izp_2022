#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial string content
const char *str_init = "Hello World!";

// Find first substring occurrence in a string and return its starting position.
// Return -1 if the string does not contain substring.
int find_substr(char *str, char *substr)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; str[i + j] == substr[j]; j++)
        {
            // We reached the end of the substring, we have a match.
            if (substr[j + 1] == '\0')
            {
                return i;
            }
        }
    }
    return -1;
}

// Replace same-length substrings in a string.
void replace_same_length(char *str, char *substr, char *new_substr)
{
    // Find the starting position of the substring, if any.
    int position = find_substr(str, substr);
    if (position == -1)
    {
        return;
    }

    // Copy the new substring content.
    for (int i = 0; new_substr[i] != '\0'; i++)
    {
        str[position + i] = new_substr[i];
    }
}

// Replace substring in a string with any new substring.
// Returns new string with replaced substring or NULL in case of any error.
char *replace(char *str, char *substr, char *new_substr)
{
    // Find the starting position.
    int position = find_substr(str, substr);
    if (position == -1)
    {
        return NULL;
    }

    // Get the necessary lengths.
    int str_len = strlen(str);
    int substr_len = strlen(substr);
    int new_substr_len = strlen(new_substr);
    int len_diff = substr_len - new_substr_len;

    if (len_diff > 0)
    {
        // The new string will be shorter, move the suffix (the rest of
        // the string) (i.e., characters after the substring) to the left.
        int i;
        for (i = position + substr_len; str[i] != '\0'; i++)
        {
            str[i - len_diff] = str[i];
        }
        str[i - len_diff] = '\0';

        // resize after shift-left the suffix
        char *new_str = (char *)realloc(str, str_len - len_diff + 1);
        if (new_str == NULL)
        {
            return NULL;
        }
        str = new_str;
    }

    if (len_diff < 0)
    {
        // The new string will be longer, move the rest of the string to the right.

        // resize before shift-right the suffix
        char *new_str = (char *)realloc(str, str_len - len_diff + 1);
        if (new_str == NULL)
        {
            return NULL;
        }
        str = new_str;

        // shift-right the suffix
        for (int i = str_len - len_diff; i >= position + substr_len; i--)
        {
            str[i] = str[i + len_diff];
        }
    }

    // Copy the contents of the new substring.
    for (int i = 0; new_substr[i] != '\0'; i++)
    {
        str[position + i] = new_substr[i];
    }

    return str;
}

int main()
{
    // Allocate new string.
    char *str = (char *)malloc(strlen(str_init) + 1);
    if (str == NULL)
    {
        return 1;
    }
    // Set the initial string by copying it.
    strcpy(str, str_init);

    // Replace substring with a new same-length substring.
    replace_same_length(str, "World!", "worlds");
    printf("%s\n", str);

    // Replace substring with a new shorter substring.
    str = replace(str, "worlds", "IZP!");
    if (str == NULL)
    {
        return 1;
    }
    printf("%s\n", str);

    // Replace substring with a new longer substring.
    str = replace(str, "IZP!", "World!");
    if (str == NULL)
    {
        return 1;
    }
    printf("%s\n", str);

    // Cleanup
    free(str);
    printf("Successully replaced all substrings!\n");

    // Allocate and initialize a new string.
    str = (char *)malloc(strlen(str_init) + 1);
    if (str == NULL)
    {
        return 1;
    }
    strcpy(str, str_init);

    // Try using replace with substring that is not in the string.
    char *new_str = replace(str, "worlds", "World!");
    if (new_str == NULL)
    {
	free(str);
	return 1;
    }
    printf("%s\n", str);


    free(str);
    return 0;
}
