#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libasm.h"


void test_strcpy(const char *src, int id) {
    char dst_std[500];
    char dst_ft[500];

    // Initialise les buffers à zéro (pas obligatoire mais propre)
    memset(dst_std, 0, sizeof(dst_std));
    memset(dst_ft, 0, sizeof(dst_ft));

    // Appelle strcpy standard
    char *ret_std = strcpy(dst_std, src);
    // Appelle ft_strcpy
    char *ret_ft = ft_strcpy(dst_ft, src);

    // Test contenu
    if (strcmp(dst_std, dst_ft) != 0) {
        printf("[❌] Contenu différent !\n");
        printf("strcpy   : \"%s\"\n", dst_std);
        printf("ft_strcpy: \"%s\"\n", dst_ft);
    } else if (ret_std != dst_std) {
        printf("[❌] strcpy ne retourne pas dst\n");
    } else if (ret_ft != dst_ft) {
        printf("[❌] ft_strcpy ne retourne pas dst\n");
    } else {
        printf("[✅] OK pour test %d = %s\n", id, src);
    }
}

int main(void)
{

    int test_id = 1;
    test_strcpy("", test_id++);
    test_strcpy("a", test_id++);
    test_strcpy("abc", test_id++);
    test_strcpy("yo tout le monde cest squeezie", test_id++);
    test_strcpy("012345678965484513241545132", test_id++);
    test_strcpy("TestAvecDesMotsSuperLongsDansUnePhraseLalalalalala", test_id++);
    test_strcpy("Avec\tdes\ttabs", test_id++);
    test_strcpy("Avec\nbackslash\nn\n", test_id++);
    test_strcpy("Terminé par null \0 au milieu", test_id++);


    char *long_str = malloc(500);
    if (!long_str) {
        perror("malloc");
        return 1;
    }
    memset(long_str, 'A', 499);
    long_str[499] = '\0';
    test_strcpy(long_str, test_id++);
    free(long_str);

    return (0);
}