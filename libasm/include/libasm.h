#ifndef LIBASM_H
#define LIBASM_H

#include <unistd.h>

/* Return the length of S.  */
extern size_t ft_strlen (const char *__s)
// ici on a copier ce quil y a dans la bibliotheque pour avoir le meme comportement
     __THROW __attribute_pure__ __nonnull ((1)); 



/* Copy SRC to DEST.  */
extern char *ft_strcpy (char *__restrict __dest, const char *__restrict __src)
     __THROW __nonnull ((1, 2));



/* Compare S1 and S2.  */
extern int ft_strcmp (const char *__s1, const char *__s2)
     __THROW __attribute_pure__ __nonnull ((1, 2));



/* Write N bytes of BUF to FD.  Return the number written, or -1.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern ssize_t ft_write (int __fd, const void *__buf, size_t __n) __wur
    __attr_access ((__read_only__, 2, 3));



/* Read NBYTES into BUF from FD.  Return the
   number read, -1 for errors or 0 for EOF.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern ssize_t ft_read (int __fd, void *__buf, size_t __nbytes) __wur
    __fortified_attr_access (__write_only__, 2, 3);



/* Duplicate S, returning an identical malloc'd string.  */
extern char *ft_strdup (const char *__s)
     __THROW __attribute_malloc__ __nonnull ((1));

#endif