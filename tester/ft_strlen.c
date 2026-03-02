#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"


void test(const char *str, int id) {
    size_t std_len = strlen(str);
    size_t ft_len = ft_strlen(str);

    if (std_len != ft_len) {
        printf("[❌] Test %d : ERREUR !\n", id);
        printf("      string : \"%s\"\n", str);
        printf("      strlen     = %zu\n", std_len);
        printf("      ft_strlen  = %zu\n", ft_len);
    } else {
        printf("[✅] Test %d OK : longueur = %zu\n", id, ft_len);
    }
}

int main(void)
{
    /* unlock les commentaires en dessous permettent de voir le comportement si on envoie null */
    // printf("len = %ld\n", ft_strlen(NULL));
    // printf("len = %ld\n", strlen(NULL));

    int test_id = 1;

    test("", test_id++);
    test("a", test_id++);
    test("abc", test_id++);
    test("yo tout le monde cest squeezie", test_id++);
    test("012345678965484513241545132", test_id++);
    test("TestAvecDesMotsSuperLongsDansUnePhraseLalalalalala", test_id++);
    test("Avec\tdes\ttabs", test_id++);
    test("Avec\nbackslash\nn\n", test_id++);
    test("Terminé par null \0 au milieu", test_id++);

    char *long_str = malloc(1000001);
    if (!long_str) {
        perror("malloc");
        return 1;
    }
    memset(long_str, 'A', 1000000);
    long_str[1000000] = '\0';
    test(long_str, test_id++);
    free(long_str);

    return (0);
}