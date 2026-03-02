#include <stdio.h>
#include <string.h>
#include "libasm.h"


int main(void)
{
    char buf[20] = "";

    printf("read = %zd\n", ft_read(1, buf, 5));
    perror("read perror ");
    printf("buf = %s\n", buf);
    printf("read = %zd\n", read(1, buf, 5));
    perror("read perror ");
    printf("buf = %s\n", buf);
    return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "libasm.h"
// #include <unistd.h>
// #include <fcntl.h>
// #include <errno.h>

// // Compare deux buffers
// int compare_buffers(const char *a, const char *b, size_t len) {
//     for (size_t i = 0; i < len; ++i) {
//         if (a[i] != b[i]) return 0;
//     }
//     return 1;
// }

// void print_buffer(const char *label, const char *buf, ssize_t len) {
//     printf("%s [len = %zd]: \"", label, len);
//     for (ssize_t i = 0; i < len; ++i) {
//         if (buf[i] >= 32 && buf[i] <= 126) putchar(buf[i]);  // printable
//         else printf("\\x%02x", (unsigned char)buf[i]);
//     }
//     printf("\"\n");
// }

// void test_read_file(const char *filename, size_t bytes_to_read) {
//     char buf_std[4096];
//     char buf_ft[4096];

//     printf("=== Test lecture fichier \"%s\" (%zu octets) ===\n", filename, bytes_to_read);

//     // Ouvre le fichier deux fois (on pourrait dupliquer fd aussi)
//     int fd1 = open(filename, O_RDONLY);
//     if (fd1 < 0) { perror("open"); return; }

//     int fd2 = open(filename, O_RDONLY);
//     if (fd2 < 0) { perror("open (2)"); close(fd1); return; }

//     // Lecture standard
//     errno = 0;
//     ssize_t ret_std = read(fd1, buf_std, bytes_to_read);
//     int errno_std = errno;

//     // Lecture ft_read
//     errno = 0;
//     ssize_t ret_ft = ft_read(fd2, buf_ft, bytes_to_read);
//     int errno_ft = errno;

//     close(fd1);
//     close(fd2);

//     // Résultat
//     if (ret_std != ret_ft) {
//         printf("[❌] Nombre d'octets lus différent :\n");
//         printf("    read()    = %zd, errno = %d\n", ret_std, errno_std);
//         printf("    ft_read() = %zd, errno = %d\n", ret_ft, errno_ft);
//         return;
//     }

//     if (!compare_buffers(buf_std, buf_ft, ret_std)) {
//         printf("[❌] Buffers différents !\n");
//         print_buffer("read()", buf_std, ret_std);
//         print_buffer("ft_read()", buf_ft, ret_ft);
//         return;
//     }

//     if (errno_std != errno_ft) {
//         printf("[❌] errno différents : read() = %d, ft_read() = %d\n", errno_std, errno_ft);
//         return;
//     }

//     printf("[✅] OK — %zd octets lus identiques\n", ret_std);
// }

// int main(void) {
//     // 🔸 Test sur un fichier texte connu (à adapter selon ce que tu as)
//     test_read_file("./tester/data/test.txt", 32);
//     test_read_file("./tester/data/test.txt", 100);
//     test_read_file("./tester/data/test.txt", 0);   // test de lecture vide
//     test_read_file("./tester/data/test.txt", 4096); // test lecture max buffer

//     // 🔸 Test avec un fichier inexistant
//     test_read_file("./tester/data/fichier_inexistant.txt", 16);

//     return 0;
// }