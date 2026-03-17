#include <stdlib.h>

char **ft_split_args(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;
    char **result;
    
    // compter les mots
    while (str[i])
    {
        while (str[i] == ' ') i++;
        if (str[i]) count++;
        while (str[i] && str[i] != ' ') i++;
    }
    
// alloue count + 2 (un pour NULL au début, un pour NULL à la fin)

    result = malloc(sizeof(char *) * (count + 2));
    if (!result) return NULL;

    result[0] = NULL;  // simule av[0]
    i = 0;
    j = 1;             // commence à remplir à partir de 1
    while (str[i])
    {
        while (str[i] == ' ') i++;
        if (!str[i]) break;
        int start = i;
        while (str[i] && str[i] != ' ') i++;
        result[j] = malloc(sizeof(char) * (i - start + 1));
        int k = 0;
        while (start < i) result[j][k++] = str[start++];
        result[j][k] = '\0';
        j++;
    }
    result[j] = NULL;
    return result;
}