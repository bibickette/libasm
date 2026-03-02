#include <stdio.h>
#include <string.h>

#include "libasm.h"

int main(void)
{
    printf("C main tester\n");
    printf("============================== STRCPY TEST ==============================\n");

    char a[] = "bonjour";
    char b[] = "au revoir";
    char c[] = "bonjour";
    char d[] = "au revoir";
    // char e[] = "bonjour";
    // char f[] = "au revoir";
    // ft_strcpy(a, b);
    printf("strcpy %s\n", strcpy(c, d));
    printf("strcpy %s\n", strcpy(a, b));
    // printf("my strcpy %s\n", ft_strcpy(c, d));
    // printf("my strcpy %s\n", ft_strcpy(a, b));
    // printf("my strcpy %s\n", ft_strcpy(e, f));

    // printf("my strcpy %s", ft_strcpy("", b));
    // printf("strcpy %s", strcpy("", b));

    printf("============================== END STRCPY ==============================\n");

    return (0);
}