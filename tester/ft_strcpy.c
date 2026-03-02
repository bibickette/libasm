#include <stdio.h>
#include <string.h>

#include "libasm.h"


// void test_strcpy(const char *src) {
//     char dst_std[100];
//     char dst_ft[100];

//     // Initialise les buffers à zéro (pas obligatoire mais propre)
//     memset(dst_std, 0, sizeof(dst_std));
//     memset(dst_ft, 0, sizeof(dst_ft));

//     // Appelle strcpy standard
//     char *ret_std = strcpy(dst_std, src);
//     // Appelle ft_strcpy
//     char *ret_ft = ft_strcpy(dst_ft, src);

//     // Test contenu
//     if (strcmp(dst_std, dst_ft) != 0) {
//         printf("[❌] Contenu différent !\n");
//         printf("strcpy   : \"%s\"\n", dst_std);
//         printf("ft_strcpy: \"%s\"\n", dst_ft);
//     } else if (ret_std != dst_std) {
//         printf("[❌] strcpy ne retourne pas dst\n");
//     } else if (ret_ft != dst_ft) {
//         printf("[❌] ft_strcpy ne retourne pas dst\n");
//     } else {
//         printf("[✅] OK pour \"%s\"\n", src);
//     }
// }



int main(void)
{
    printf("C main tester\n");
    printf("============================== STRCPY TEST ==============================\n");

    char a[20] = "bonjour";
    char b[10] = "au revoir";
    char c[] = "beeeeeeeeeeeeeeeerrrrrr";
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
    // test_strcpy("");
    // test_strcpy("Hello");
    // test_strcpy("Une chaîne avec espaces");
    // test_strcpy("String avec \0 caractère nul interne"); // Attention: strcpy s’arrête au \0
    // test_strcpy("0123456789abcdefghijklmnopqrstuvwxyz");

    printf("============================== END STRCPY ==============================\n");

    return (0);
}