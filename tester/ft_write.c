#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"
#include <errno.h>

#define FT_WRITE 1

void test_write(int fd, const void *data, size_t len, int id, ssize_t (*function)(int, const void *, size_t), int flag_write_or_ft) {
    ssize_t ret = function(fd, data, len);
    if (ret < 0) {
        if(flag_write_or_ft == FT_WRITE)
        {
            printf("[❌] Test %d ft_write : error code = %ld\n", id, ret);
            perror("ft_write");
        }
        else
        {
            printf("[❌] Test %d : error code = %ld\n", id, ret);
            perror("write");
        }
    } else {
        if(flag_write_or_ft == FT_WRITE)
        {
            printf("[✅] Test %d ft_write a écrit %zd octets\n", id, ret);
        }
        else
        {
            printf("[✅] Test %d a écrit %zd octets\n", id, ret);
        }
    }
}

void test_both_write(int fd_ft, int fd_regular, char *data, size_t len, int id){
    test_write(fd_ft, data, len, id, ft_write, FT_WRITE);
    test_write(fd_regular, data, len, id, write, WRITE);
}


int main(void) {
    int id = 1;


    int fd_ft = open("test_ft_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_ft < 0) {
        perror("open");
        return 1;
    }
    int fd_regular = open("test_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_regular < 0) {
        close(fd_ft);
        perror("open");
        return 1;
    }

    test_both_write(fd_ft, fd_regular,"first test\n", ft_strlen("first_test\n"), id++);
    test_both_write(fd_ft, fd_regular,"write extra memory", 25, id++);
    test_both_write(fd_ft, fd_regular,"\nnot enough len", 11, id++);
    test_both_write(fd_ft, fd_regular,"\ntest with null in the middle \n\0 of a sentence", ft_strlen("\ntest with null in the middle \n\0 of a sentence"), id++);

    char *long_str = malloc(1024);
    if (!long_str) {
        perror("malloc");
        return 1;
    }
    memset(long_str, 'A', 1023);
    long_str[1023] = '\0';
    test_both_write(fd_ft, fd_regular, long_str, 1024, id++);
    free(long_str);

    close(fd_ft);
    close(fd_regular);

    // test with stdin stdout stderr and invalid fd
    test_both_write(0, 0, "is printed in stdin\n", ft_strlen("is printed in stdin\n"), id++);
    test_both_write(1, 1, "is printed in stdout\n", ft_strlen("is printed in stdout\n"), id++);
    test_both_write(1, 1, "is printed in stdout\n", ft_strlen("is printed in stdout\n"), id++);
    test_both_write(-1, -1, "is printed in negative fd\n", ft_strlen("is printed in negative fd\n"), id++);
    test_both_write(10, 10, "is printed in fd 10 that does not exist\n", ft_strlen("is printed in negative fd\n"), id++);
    

    return 0;
}
