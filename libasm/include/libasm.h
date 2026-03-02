#ifndef LIBASM_H
#define LIBASM_H

#include <unistd.h>

extern size_t ft_strlen(const char *s)
// ici on a copier ce quil y a dans la bibliotheque pour avoir le meme comportement
     __THROW __attribute_pure__ __nonnull ((1)); 

extern char * ft_strcpy( char * destination, const char * source )
     __THROW __nonnull ((1, 2));



#endif