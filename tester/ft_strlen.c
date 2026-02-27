#include <stdio.h>
#include <string.h>

#include "libasm.h"

int main(void)
{
    printf("C main tester\n");
    printf("============================== STRLEN TEST ==============================\n");
    printf("len of \"yo tout le monde\" = %ld\n", strlen("yo tout le monde"));
    printf("my strlen of \"yo tout le monde\" = %ld\n", ft_strlen("yo tout le monde"));
    printf("len = %ld\n", ft_strlen(""));
    // printf("len = %ld\n", ft_strlen(NULL));
    // printf("len = %ld\n", strlen(NULL));
    printf("============================== END STRLEN ==============================\n");

    return (0);
}