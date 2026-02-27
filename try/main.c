#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *s)
// ici on a copier ce quil y a dans la bibliotheque pour avoir le meme comportement
     __THROW __attribute_pure__ __nonnull ((1)); 

extern char * ft_strcpy( char * destination, const char * source )
     __THROW __nonnull ((1, 2));


int main(void)
{
    printf("C main tester\n");
    printf("len of \"yo tout le monde\" = %ld\n", strlen("yo tout le monde"));
    printf("my strlen of \"yo tout le monde\" = %ld\n", ft_strlen("yo tout le monde"));
    printf("len = %ld\n", ft_strlen(""));
    // printf("len = %ld\n", ft_strlen(NULL));
    // printf("len = %ld\n", strlen(NULL));

    char a[] = "bonjour";
    char b[] = "au revoir";
    char c[] = "bonjour";
    char d[] = "au revoir";
    // char e[] = "bonjour";
    // char f[] = "au revoir";
    // ft_strcpy(a, b);
    printf("strcpy %s\n", strcpy(c, d));
    printf("strcpy %s\n", strcpy(a, b));
    // printf("my strcpy %s\n", ft_strcpy(c, d));
    // printf("my strcpy %s\n", ft_strcpy(a, b));
    // printf("my strcpy %s\n", ft_strcpy(e, f));

    // printf("my strcpy %s", ft_strcpy("", b));
    // printf("strcpy %s", strcpy("", b));

    return (0);
}