#include <stdio.h>
#include <string.h>
#include "libasm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

bool compare_buffers(const char *a, const char *b, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void test_both_read(int fd_ft, int fd_std, char *buf_ft, char *buf_std, size_t len, int id)
{
    errno = 0; // reset errno before the call

    ssize_t ret_ft = ft_read(fd_ft, buf_ft, len);
    if (ret_ft < 0)
    {
        printf("[❌] Test %d ft_read : error code = %d\n", id, errno);
        perror("ft_read");
    }
    else
    {
        printf("[✅] Test %d ft_read a lu %zd octets\n", id, ret_ft);
    }
    
    ssize_t ret_std = read(fd_std, buf_std, len);
    if (ret_std < 0)
    {
        printf("[❌] Test %d read : error code = %d\n", id, errno);
        perror("read");
    }
    else
    {
        printf("[✅] Test %d read a lu %zd octets\n", id, ret_std);
    }

    if (ret_ft < 0 || ret_std < 0)
    {
        printf("\n");
        return;
    }

    if (ret_std != ret_ft)
    {
        printf("[❌] Nombre d'octets lus différent :\n");
        printf("    ft_read() = %zd, errno = %d\n", ret_ft, errno);
        printf("    read()    = %zd, errno = %d\n", ret_std, errno);
        printf("\n");
        return;
    }
    if (!compare_buffers(buf_std, buf_ft, ret_std))
    {
        printf("[❌] Buffers différents !\n");
        printf("ft_read(): %s ", buf_ft);
        printf("read(): %s ", buf_std);
        printf("\n");
        return;
    }
    printf("\n");
}

int all_ft_read(void)
{
    printf("\n=================== Tests de ft_read ===================\n\n");
    int id = 1;

    int fd_read = open("./tester/data/test.txt", O_RDONLY);
    if (fd_read < 0)
    {
        perror("open");
        return 1;
    }
    int fd_std = open("./tester/data/test.txt", O_RDONLY);
    if (fd_std < 0)
    {
        perror("open");
        return 1;
    }
    char buf_read[4096] = "";
    char buf_std[4096] = "";

    test_both_read(fd_read, fd_std, buf_read, buf_std, 2048, id++);
    test_both_read(fd_read, fd_std, buf_read, buf_std, 1024, id++);
    test_both_read(fd_read, fd_std, buf_read, buf_std, 500, id++);
    test_both_read(fd_read, fd_std, buf_read, buf_std, 10, id++);
    test_both_read(fd_read, fd_std, buf_read, buf_std, 42, id++);
    test_both_read(fd_read, fd_std, buf_read, buf_std, -2, id++);
    test_both_read(-1, -1, buf_read, buf_std, 10, id++);

    close(fd_read);
    close(fd_std);
    return (0);
}
