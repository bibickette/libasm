# Project presentation - `libasm`
## Description
**libasm** is a beginner-friendly project written in **x86_64 (64-bit) assembly**, aiming to recreate a small library that re-implements a set of classic **libc-like** functions.

The goal is to understand what happens “under the hood” in C programs by working directly with:
- registers and the stack
- calling conventions
- system calls (syscalls)
- memory and strings at a low level

* * *

## Languages & Technologies

### Languages
- **Assembly (x86_64)** : core language of the project (64-bit)
- **C** : used to write small test programs and compare behavior with libc

### Technologies
- **NASM**
- **Makefile** 

* * *

## Key Concepts

1. **Calling convention (System V AMD64 ABI)**  
   On Linux/macOS x86_64, arguments are typically passed in registers:
   - `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9` (first 6 integer/pointer args)
   - return value in `rax`

2. **Registers & data movement**
   - working with `rax`, `rbx`, `rcx`, `rdx`, `rdi`, `rsi`, etc.
   - understanding the difference between 8/16/32/64-bit register parts (`al`, `eax`, `rax`, …)

3. **Stack basics**
   - saving/restoring registers when needed
   - keeping the stack aligned (important for some calls)

4. **Strings in C**
   - null-terminated arrays of bytes (`'\0'`)
   - manual iteration to find length, copy, compare, etc.

5. **Error handling**
   - some functions must set `errno` 
   - syscalls may return negative values or set error codes

6. **Static library**
   - compiling multiple `.o` files and packing them into `libasm.a`
   - linking it like a normal C library

* * *

## What’s included in the library

**Core libc-like functions**
- `ft_strlen` : returns the length of a string.
- `ft_strcpy` : copies a string from `src` to `dst`.
- `ft_strcmp` : compares two strings.
- `ft_strdup` : duplicates a string (allocates memory and copies).
- `ft_write` : writes to a file descriptor (usually via syscall or libc wrapper, depending on requirements).
- `ft_read` : reads from a file descriptor.


* * *

# How to use `libasm`

## Makefile rules

Typical Makefile targets (adapt as needed):
1. **all** : build `libasm.a`
2. **clean** : remove `.o` object files
3. **fclean** : remove `.o` and `libasm.a`
4. **re** : *fclean* + *all*
5. **test** : build and run all tests programs

## How to use `libasm`

1. Clone `libasm` in a folder first  : `git clone git@github.com:bibickette/libasm.git`
2. Go to the `libasm` folder then compile it : `cd libasm && make` ; it will generate an executable for each function in the library
3. You can now run a specific function test : `./ft_strlen`, or run all tests at once : `make test`


## Valgrind & memory checks

*`libasm` was tested using **Valgrind** to ensure there are no memory leaks and that all allocated memory is properly freed.*

You can run tests with **Valgrind** using the following command : `valgrind --leak-check=full --show-leak-kinds=all ./ft_strdup`


* * *

*Project validation date : TBD*