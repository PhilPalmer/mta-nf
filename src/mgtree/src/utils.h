
#ifndef UTILS_H
#define	UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <sys/times.h>
#include <sys/time.h>
#include <time.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>

#define PROGRAM "mGTree"
#define VERSION "1.0.1"
#define AUTHOR "Miquel Orobitg"

#define TRUE 1
#define FALSE  0
#define OPTIONAL 1
#define NON_OPTIONAL 0
#define FILENAMELEN 500
#define ALLPATH 1000
#define MEMSET0 1
#define NO_MEMSET0 0
#define MY_EPS 1000*DBL_EPSILON
#define STRING           300
#define NSCORE 7
#define NSCORE_TOTAL 10

#define COMMENT_SIZE 1000
#define MAXNAMES 100
#define GAP_LIST "-.#*~"
#define AA_ALPHABET "acdefghiklmnpqrstvwy-ACDEFGHIKLMNPQRSTVWY"
#define DNA_ALPHABET "AGCTUNRYMKSWHBVD-agctunrymkswhbvd"
#define RNAONLY_ALPHABET "Uu"
#define END_ARRAY -99999990
#define SCORE_K 10
#define MAXID 100
#define MAX_N_PARAM 2000
#define SEPARATORS "\n \t,;"

#define TAG_MSTREE 10
#define TAG_WSSCORE 11
#define FIN_MSG -11

#define MIN(x, y) (((x) <(y)) ? (x):(y))
#define MAX(x, y) (((x) >(y)) ? (x):(y))

#define declare_name(x) (x=vcalloc (MAX(FILENAMELEN,L_tmpnam)+1, sizeof (char))) 

#define strm(x, y) (vstrcmp((x), (y)) == 0)
#define strm2(a, b, c) (strm(a, b) || strm(a, c))
#define strm3(a, b, c, d) (strm2(a, b, c) || strm(a, d))
#define strm4(a, b, c, d, e) (strm2(a, b, c) || strm2(a, d, e))
#define strm5(a, b, c, d, e, f) (strm2(a, b, c) || strm3(a, d, e, f))
#define strm6(a, b, c, d, e, f, g) (strm3(a, b, c, d) || strm3(a, e, f, g))
#define strnm(x, y, n) (vstrncmp((x), (y), (n)) == 0)
#define is_parameter(x) (x[0]=='-' && !isdigit(x[1]))

struct Memcontrol{
      size_t size;
      size_t size_element;
      char check[3];
      struct Memcontrol *p;
      struct Memcontrol *n;
};
typedef struct Memcontrol Memcontrol;

//Names struct
typedef struct
{
    char *name;
    char *path;
    char *suffix;
    char *full;
}
Fname;

FILE *openfile(const char *filename, const char *mode);

Fname *declare_fname (int size);
Fname *free_fname(Fname *F);
Fname *parse_fname(char* array);

void remove_file(char *file);


FILE* skip_space(FILE *fp);
int name_is_in_list(char *name, char **name_list, int n_name, int len);

double get_time();
int vstrcmp(const char *s1, const char *s2);
int vstrncmp(const char *s1, const char *s2, int n);

int read_array_size( void  *array, size_t size );
int read_array_size_new( void  *array);
int is_dynamic_memory( void *array);
int verify_memory(int s);
void  vfree( void *p);
void * vmalloc( size_t size);
void * sub_vcalloc( size_t nobj, size_t size, int MODE);
void * vcalloc( size_t nobj, size_t size);
void *vcalloc_nomemset ( size_t nobj, size_t size);
void * vrealloc( void *p, size_t size);
void *ckalloc(size_t bytes);
void *ckvrealloc(void *ptr, size_t bytes);
void ckfree(void *ptr);

/*********************************************************************/
/*                                                                   */
/*                          REALLOCATION                             */
/*                                                                   */
/*                                                                   */
/*********************************************************************/
void **realloc_arrayN(int ndim,void **main_array,size_t size, ...);
void **realloc_arrayN2 ( int ndim, void ** p, int *A, size_t size);


void ** realloc_array (void **array,size_t size, int first, int second, int ext1, int ext2);
short     ** realloc_short     ( short     **array, int first, int second, int ext1, int ext2);
char      ** realloc_char      ( char      **array, int first, int second, int ext1, int ext2);
int       ** realloc_int       ( int       **array, int first, int second, int ext1, int ext2);
float     ** realloc_float     ( float     **array, int first, int second, int ext1, int ext2);
double    ** realloc_double    ( double    **array, int first, int second, int ext1, int ext2);

/*The new realloc is recommended*/
short     ** new_realloc_short     ( short     **array, int ext1, int ext2);
char      ** new_realloc_char      ( char      **array, int ext1, int ext2);
int       ** new_realloc_int       ( int       **array, int ext1, int ext2);
float     ** new_realloc_float     ( float     **array, int ext1, int ext2);
double    ** new_realloc_double    ( double    **array, int ext1, int ext2);


void * declare_arrayNnomemset (int ndim, size_t size, ...);
void *declare_arrayN2nomemset ( int ndim, int *A, size_t size);

void * declare_arrayN (int ndim, size_t size, ...);
void *declare_arrayN2 ( int ndim, int *A, size_t size);


void      ** declare_array     (int first, int second, size_t size);
short     ** declare_short     ( int first, int second);
char      ** declare_char      ( int first, int second);
int       ** declare_int       ( int first, int second);
int       ** declare_int2       ( int first, int *second, int delta);

float     ** declare_float     ( int first, int second);
double    ** declare_double    ( int first, int second);

void      ** declare_array_nomemset     (int first, int second, size_t size);
short     ** declare_short_nomemset      ( int first, int second);
char      ** declare_char_nomemset       ( int first, int second);
int       ** declare_int_nomemset        ( int first, int second);
float     ** declare_float_nomemset      ( int first, int second);
double    ** declare_double_nomemset     ( int first, int second);


short     **  free_short    ( short     **array, int first);
int       **  free_int      ( int       **array, int first);
char      **  free_char     ( char      **array, int first);
double    ** free_double    ( double    **array, int first);
float     ** free_float     ( float     **array, int first);

int **duplicate_int(int **array, int len, int field);
int **copy_int(int **array1, int **array2, int len, int number_field);
int *ga_memcpy_int(int *array1, int *array2, int n);
int **sim_array2dist_array(int **p, int max);
int **normalize_array(int **p, int max, int norm);


#endif	/* UTILS_H */

