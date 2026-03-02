#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <stdlib.h>



// int main(void)
// {
//     char src[] = "yo";
//     char *std_res = strdup(src);
//     char *ft_res = ft_strdup(src);
//     printf("strdup   : \"%s\"\n", std_res);
//     printf("ft_strdup: \"%s\"\n", ft_res);

//     return (0);
// }




void test_strdup(const char *src) {
    char *std_res = strdup(src);
    char *ft_res = ft_strdup(src);

    if (!std_res) {
        printf("[❌] strdup standard a retourné NULL\n");
        return;
    }
    if (!ft_res) {
        printf("[❌] ft_strdup a retourné NULL\n");
        free(std_res);
        return;
    }

    if (strcmp(std_res, ft_res) != 0) {
        printf("[❌] Contenu différent !\n");
        printf("strdup   : \"%s\"\n", std_res);
        printf("ft_strdup: \"%s\"\n", ft_res);
    } else {
        printf("[✅] OK pour \"%s\"\n", src);
    }

    free(std_res);
    free(ft_res);
}

int main(void) {
    test_strdup("");
    test_strdup("Hello, world!");
    test_strdup("Une chaîne avec espaces");
    test_strdup("0123456789abcdefghijklmnopqrstuvwxyz");

    return 0;
}