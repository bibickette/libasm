#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <stdlib.h>


void test_strdup(const char *src, int id) {
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
        printf("[✅] OK pour test %d = \"%s\"\n", id, src);
    }

    free(std_res);
    free(ft_res);
}

int main(void) {
    int test_id = 1;

    test_strdup("", test_id++);
    test_strdup("a", test_id++);
    test_strdup("abc", test_id++);
    test_strdup("yo tout le monde cest squeezie", test_id++);
    test_strdup("012345678965484513241545132", test_id++);
    test_strdup("TestAvecDesMotsSuperLongsDansUnePhraseLalalalalala", test_id++);
    test_strdup("Avec\tdes\ttabs", test_id++);
    test_strdup("Avec\nbackslash\nn\n", test_id++);
    test_strdup("Terminé par null \0 au milieu", test_id++);

    return 0;
}