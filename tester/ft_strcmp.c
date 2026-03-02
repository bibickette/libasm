#include <stdio.h>
#include <string.h>
#include "libasm.h"

// void test_strcmp(const char *s1, const char *s2) {
//     int res_std = strcmp(s1, s2);
//     int res_ft  = ft_strcmp(s1, s2);

//     if ((res_std == 0 && res_ft == 0) || (res_std < 0 && res_ft < 0) || (res_std > 0 && res_ft > 0)) {
//         printf("[✅] OK pour \"%s\" vs \"%s\"\n", s1, s2);
//     } else {
//         printf("[❌] Différence détectée pour \"%s\" vs \"%s\"\n", s1, s2);
//         printf("strcmp   = %d\n", res_std);
//         printf("ft_strcmp= %d\n", res_ft);
//     }
// }

int main(void) {
    // test_strcmp("", "");

    printf("my strcmp %d\n", ft_strcmp("a", "a"));
    printf("strcmp %d\n", strcmp("a", "a"));
    // test_strcmp("abc", "abc");
    // test_strcmp("abc", "abcd");
    // test_strcmp("abcd", "abc");
    // test_strcmp("hello", "world");
    // test_strcmp("test", "test");
    // test_strcmp("a", "b");
    // test_strcmp("abc\0def", "abc");
    // test_strcmp("abc", "abc\0def");

    return 0;
}