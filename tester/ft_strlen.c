#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"


void test_one(const char *str, int id) {
    size_t std_len = strlen(str);
    size_t ft_len = ft_strlen(str);

    if (std_len != ft_len) {
        printf("[❌] Test %d : ERREUR !\n", id);
        printf("      Chaîne : \"%s\"\n", str);
        printf("      strlen     = %zu\n", std_len);
        printf("      ft_strlen  = %zu\n", ft_len);
    } else {
        printf("[✅] Test %d : OK — longueur = %zu\n", id, ft_len);
    }
}



int main(void)
{
    printf("C main tester\n");
    printf("============================== STRLEN TEST ==============================\n");
    printf("len of \"yo tout le monde\" = %ld\n", strlen("yo tout le monde"));
    printf("my strlen of \"yo tout le monde\" = %ld\n", ft_strlen("yo tout le monde"));
    printf("len = %ld\n", ft_strlen(""));
    // printf("len = %ld\n", ft_strlen(NULL));
    // printf("len = %ld\n", strlen(NULL));

    // Test une chaîne et compare avec strlen de la libc

    printf("=== TEST ft_strlen vs libc strlen ===\n\n");

    int test_id = 1;

    // Cas simples
    test_one("", test_id++);
    test_one("a", test_id++);
    test_one("abc", test_id++);
    test_one("abcdefghijklmnopqrstuvwxyz", test_id++);
    test_one("0123456789", test_id++);
    test_one("Ceci est une chaîne avec des espaces.", test_id++);
    test_one("Avec\tdes\tonglets", test_id++);
    test_one("Avec\nsauts\nde\nligne", test_id++);
    test_one("Terminé par \0 au milieu", test_id++);  // volontaire : "Terminé par "

    // Chaîne longue
    char *long_str = malloc(1000001);
    if (!long_str) {
        perror("malloc");
        return 1;
    }
    memset(long_str, 'A', 1000000);
    long_str[1000000] = '\0';
    test_one(long_str, test_id++);
    free(long_str);

    // Chaînes avec caractères non ASCII
    test_one("éèêëàäâùüûçœ", test_id++);
    test_one("こんにちは世界", test_id++); // UTF-8 multioctets

    // Chaîne avec caractères nuls au milieu (attention, strlen s'arrête au 1er \0)
    const char test_with_null[] = { 'H', 'e', 'l', 'l', 'o', '\0', 'X', 'X', 'X', '\0' };
    test_one(test_with_null, test_id++);

    printf("\n=== FIN DES TESTS ===\n");

    return (0);
}