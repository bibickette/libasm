#include <stdio.h>
#include <string.h>
#include "libasm.h"

void test_strcmp(const char *s1, const char *s2, int id) {
    int res_std = strcmp(s1, s2);
    int res_ft  = ft_strcmp(s1, s2);

    if ((res_std == 0 && res_ft == 0) || (res_std < 0 && res_ft < 0) || (res_std > 0 && res_ft > 0)) {
        printf("[✅] OK pour test %d : \"%s\" vs \"%s\" | res = %d\n", id, s1, s2, res_ft);
    } else {
        printf("[❌] Différence détectée pour \"%s\" vs \"%s\"\n", s1, s2);
        printf("strcmp   = %d\n", res_std);
        printf("ft_strcmp= %d\n", res_ft);
    }
}

int all_ft_strcmp(void) {
    int test_id = 1;
    test_strcmp("", "", test_id++);
    test_strcmp("rien", "", test_id++);
    test_strcmp("a", "a", test_id++);
    test_strcmp("a", "A", test_id++);
    test_strcmp("abc", "abc", test_id++);
    test_strcmp("yo tout le monde cest squeezie", "yo tout le monde cest skezie", test_id++);
    test_strcmp("abcd", "abc", test_id++);
    test_strcmp("hello", "world", test_id++);
    test_strcmp("test", "test", test_id++);
    test_strcmp("a", "b", test_id++);
    test_strcmp("abc\0def", "abc", test_id++);
    test_strcmp("abc", "abc\0def", test_id++);

    return 0;
}