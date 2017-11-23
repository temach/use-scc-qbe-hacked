/* See LICENSE file for copyright and license details. */
#ifndef _ASSERT_H
#define _ASSERT_H

#ifndef NDEBUG
#define assert(exp) __assert(exp, #exp, __FILE__, __LINE__)
#endif

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _CTYPE_H
#define _CTYPE_H

int isalnum(int c);
int isalpha(int c);
int islower(int c);
int isupper(int c);
int isdigit(int c);
int isxdigit(int c);
int iscntrl(int c);
int isgraph(int c);
int isspace(int c);
int isblank(int c);
int isprint(int c);
int ispunct(int c);
int tolower(int c);
int toupper(int c);

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _ERRNO_H
#define _ERRNO_H

extern int errno;

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _SIGNAL_H
#define _SIGNAL_H

void ( *signal(int signum, void (*handler)(int)) ) (int);
int raise(int sig);

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _STDINT_H_
#define _STDINT_H_

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

typedef signed char int8_least_t;
typedef short int16_least_t;
typedef int int32_least_t;
typedef long int64_least_t;

typedef unsigned char uint8_least_t;
typedef unsigned short uint16_least_t;
typedef unsigned int uint32_least_t;
typedef unsigned long uint64_least_t;

typedef int int8_fast_t;
typedef int int16_fast_t;
typedef int int32_fast_t;
typedef long int64_fast_t;

typedef unsigned int8_fast_t;
typedef unsigned int16_fast_t;
typedef unsigned int32_fast_t;
typedef unsigned long int64_fast_t;

typedef long intptr_t;
typedef unsigned long uintptr_t;

typedef long intmax_t;
typedef unsigned long uintmax_t;

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _STDIO_H
#define _STDIO_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef _SIZET
typedef unsigned long size_t;
#define _SIZET
#endif

#define EOF            -1
#define BUFSIZ        512
#define FILENAME_MAX  256
#define FOPEN_MAX      16
#define _IOFBF          0
#define _IOLBF          1
#define _IONBF          2
#define L_tmpnam      256
#define SEEK_CUR        0
#define SEEK_END        1
#define SEEK_SET        2
#define TMP_MAX        25

typedef struct _FILE FILE;

extern FILE *fopen(const char *, const char *mode);
extern FILE *freopen(const char *path, const char *mode, FILE *fp);
extern int fclose(FILE *fp);

extern int fflush(FILE *fp);
extern void setbuf(FILE *fp, char *buf);
extern int setvbuf(FILE *fp, char *buf, size_t size);

extern size_t fread(void *ptr, size_t size, size_t n, FILE *fp);
extern size_t fwrite(const void *ptr, size_t size, size_t n, FILE *fp);

extern int fgetc(FILE *fp);
extern int getc(FILE *fp);
extern int getchar(void);

extern int fputc(int c, FILE *fp);
extern int putc(int c, FILE *fp);
extern int putchar(int c);

extern char *fgets(char *s, int size, FILE *fp);
extern char *gets(char *s);

extern int fputs(char *s, FILE *fp);
extern int puts(char *s);

extern int scanf(const char *fmt, ...);
extern int fscanf(FILE *fp, const char *fmt, ...);
extern int sscanf(char *s, const char *fmt, ...);

extern int printf(const char *fmt, ...);
extern int fprintf(FILE *fp, const char *fmt, ...);
extern int sprintf(char *s, const char *fmt, ...);
extern int snprintf(char *s, size_t size, const char *fmt, ...);

extern void perror(const char *s);

extern long ftell(FILE *fp);
extern long fseek(FILE *fp);
extern void rewind(FILE *fp);

extern void clearerr(FILE *fp);
extern int feof(FILE *fp);
extern int ferror(FILE *fp);

extern int remove(const char *name);
extern int rename(const char *old, const char *new);
extern FILE *tmpfile(void);
extern FILE *tmpnam(char *s);

extern FILE *stdin, *stdout, *stderr;
#endif
/* See LICENSE file for copyright and license details. */
#ifndef _STDLIB_H
#define _STDLIB_H

#ifndef _SIZET
typedef unsigned long size_t;
#define _SIZET
#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX     32767

extern double atof(const char *ptr);
extern int atoi(const char *s);
extern long atol(const char *s);
extern long long atoll(const char *s);

extern float strtof(const char *s, char **end);
extern double strtod(const char *s, char **end);
extern long double strtold(const char *s, char **end);

extern long strtol(const char *s, char **end, int base);
extern long long strtoll(const char *s, char **end, int base);
extern unsigned long stroul(const char *s, char **end, int base);
extern unsigned long long stroull(const char *s, char **end, int base);

extern void *calloc(size_t nitems, size_t size);
extern void free(void *ptr);
extern void *realloc(void *ptr, size_t size);

extern void abort(void);
extern int atexit(void (*func)(void));
extern void exit(int status);
extern char *getenv(const char *name);
extern int system(const char *cmd);

extern void *bsearch(const void *key,
                     const void *base, size_t nitems, size_t size,
                     int (*cmp)(const void *, const void *));
extern void qsort(void *base, size_t nitems, size_t size,
                  int (*cmp)(const void *, const void *));

extern void abs(int x);
/* div_t div(int num, int denom); */
extern long labs(long int x);
/* ldiv_t ldiv(long int number, long int denom); */

extern int rand(void);
extern void srand(unsigned seed);

#endif
/* See LICENSE file for copyright and license details. */
#ifndef _STRING_H
#define _STRING_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef _SIZET
typedef unsigned size_t;
#endif

extern char *strcpy(char *dst, const char *src);
extern char *strncpy(char *dst, const char *src, size_t n);
extern char *strcat(char *dst, const char *src);
extern char *strncat(char *dst, const char *src, size_t n);
extern size_t strxfrm(char *dst, const char *src, size_t n);
extern size_t strlen(const char *s);
extern int strcmp(const char *s1, const char *s2);
extern int strcoll(const char *s1, const char *s2);
extern char *strchr(const char *s, int c);
extern char *strrchr(const char *s, int c);
extern size_t strspn(const char *s, const char *accept);
extern size_t strcspn(const char *s, const char *reject);
extern size_t strpbrk(const char *s, const char *accept);
extern size_t strstr(const char *s, const char *sub);
extern char *strtok(const char *s, const char *delim);

extern void *memset(void *s, int c, size_t n);
extern void *memcpy(void *dst, const void *src, size_t n);
extern void *memmove(void *dst, const void *src, size_t n);
extern int memcmp(const void *s1, const void *s2, size_t n);
extern void *memchr(const void *s, int c, size_t n);

#endif
