// #include <stdio.h>
// #include <string.h>
// #include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"
#include <unistd.h>
#include <errno.h>

int main(void) {
    char a[] = "bonjour";

    printf(" write returns %zd\n", write(1, a, strlen(a)));
    perror(" write error");
    printf(" my write returns %zd\n", ft_write(1, a, ft_strlen(a)));
    perror(" my write error");

    return 0;
}

// Compare deux fichiers octet par octet
// int compare_files(const char *file1, const char *file2) {
//     FILE *f1 = fopen(file1, "rb");
//     FILE *f2 = fopen(file2, "rb");
//     if (!f1 || !f2) {
//         perror("fopen");
//         return 0;
//     }

//     int res = 1;
//     while (1) {
//         int c1 = fgetc(f1);
//         int c2 = fgetc(f2);
//         if (c1 != c2) {
//             res = 0;
//             break;
//         }
//         if (c1 == EOF || c2 == EOF) break;
//     }

//     fclose(f1);
//     fclose(f2);
//     return res;
// }

// void test_write_case(const char *label, const char *data, size_t len) {
//     const char *file_std = "out_std.txt";
//     const char *file_ft = "out_ft.txt";

//     // Ouvre deux fichiers en écriture
//     int fd_std = open(file_std, O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     int fd_ft  = open(file_ft,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd_std < 0 || fd_ft < 0) {
//         perror("open");
//         return;
//     }

//     // Écriture avec write()
//     errno = 0;
//     ssize_t ret_std = write(fd_std, data, len);
//     int errno_std = errno;
//     close(fd_std);

//     // Écriture avec ft_write()
//     errno = 0;
//     ssize_t ret_ft = ft_write(fd_ft, data, len);
//     int errno_ft = errno;
//     close(fd_ft);

//     printf("=== Test: %s ===\n", label);

//     // Comparaison
//     if (ret_std != ret_ft) {
//         printf("[❌] Valeur de retour différente : write=%zd, ft_write=%zd\n", ret_std, ret_ft);
//     } else if (errno_std != errno_ft) {
//         printf("[❌] errno différent : write=%d, ft_write=%d\n", errno_std, errno_ft);
//     } else if (!compare_files(file_std, file_ft)) {
//         printf("[❌] Contenu écrit différent !\n");
//     } else {
//         printf("[✅] OK — %zd octets écrits identiques\n", ret_std);
//     }

//     printf("\n");
// }

// int main(void) {
//     test_write_case("Chaîne simple", "Bonjour le monde\n", 17);
//     test_write_case("Chaîne vide", "", 0);
//     test_write_case("Chaîne binaire", "\x00\x01\x02HELLO\xff", 10);
//     test_write_case("Chaîne avec \\0", "AB\0CD", 5);  // write() écrit bien les \0

//     // Test sur un FD invalide
//     errno = 0;
//     ssize_t ret_std = write(-1, "Test", 4);
//     int err_std = errno;

//     errno = 0;
//     ssize_t ret_ft = ft_write(-1, "Test", 4);
//     int err_ft = errno;

//     printf("=== Test: FD invalide ===\n");
//     if (ret_std != ret_ft || err_std != err_ft) {
//         printf("[❌] Différence sur FD invalide : write=%zd (errno=%d), ft_write=%zd (errno=%d)\n",
//             ret_std, err_std, ret_ft, err_ft);
//     } else {
//         printf("[✅] OK — les deux ont échoué de la même manière (errno=%d)\n", err_std);
//     }

//     return 0;
// }