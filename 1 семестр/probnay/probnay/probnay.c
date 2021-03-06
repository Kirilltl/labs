#include<stdio.h>
#include<stdlib.h>
int length_word(char* a)
{
    int res = 0;
    for (int i = 0; a[i] != '\0'; i++)
        res++;
    return res;
}
void twist_word(char* b)
{
    int len = length_word(b);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = b[i];
        b[i] = b[len - 1 - i];
        b[len - 1 - i] = temp;
    }
}
int is_alpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
char* get_string(int* len)
{
    *len = 0;
    int capacity = 1;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL)
    {
        free(str);
        exit(1);
    }
    char c = getchar();
    while (c != '\n') 
    {
        str[(*len)++] = c;
        if (*len >= capacity)
        {
            capacity *= 2;
            char* temp = (char*)realloc(str, capacity * sizeof(char));
            if (temp != NULL)
            {
                str = temp;
            }
            else
            {
                free(str);
                exit(1);
            }
        }
        c = getchar();
    }
    str[*len] = '\0';
    return str;
}
char** get_words(char* str, int* wc)
{
    *wc = 0;
    int flag = 1;
    int capacity = 1;
    char** words = (char**)malloc(sizeof(char*));
    if (words == NULL)
    {
        free(str);
        free(words);
        exit(1);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (is_alpha(str[i]) == 1 && flag)
        {
            words[*wc] = &str[i];
            (*wc)++;
            flag = 0;
            if (*wc >= capacity)
            {
                capacity *= 2;
                char** temp = (char**)realloc(words, capacity * sizeof(char*));
                if (temp != NULL)
                {
                    words = temp;
                }
                else
                {
                    free(str);
                    free(words);
                    exit(1);
                }
            }
        }
        else if (is_alpha(str[i]) == 0)
        {
            str[i] = '\0';
            flag = 1;
        }
    }
    return words;
}
int main()
{
    printf("Input string:");
    int len;
    char* str = get_string(&len);
    int wc;
    char** words = get_words(str, &wc);
    for (int i = 0; i < wc; i++)
    {
        twist_word(words[i]);
        printf("This is an inverted word: %s\n", words[i]);
    }
    free(str);
    free(words);
    return 0;
}
