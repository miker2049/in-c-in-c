#ifndef GEELIB_H_
#define GEELIB_H_
#import "cvector.h"

typedef char gchar;
typedef void *gpointer;
typedef const gpointer gconstpointer;
typedef const void *guint;
typedef int gint;

typedef struct _GPtrArray GPtrArray;
struct _GPtrArray {
  gpointer *pdata;
  guint len;
};

#define g_message(...) printf(__VA_ARGS__)
#define g_critical(...) printf(__VA_ARGS__)
#define g_ptr_array_new() { .pdata = NULL, .len = 0 }

#define g_ptr_array_free(arr, b) cvector_free(arr)

#define g_ptr_array_index(arr, idx) arr->pdata[idx]

#define g_ptr_array_add(arr, item)                                             \
  do {                                                                         \
    cvector_push_back(arr->pdata, item);                                       \
    arr->len += 1;                                                             \
  } while (0)

#define g_ptr_array_remove_index(arr, idx)                                     \
  do {                                                                         \
    cvector_erase(arr, idx);                                                   \
    arr->len -= 1;                                                             \
  } while (0)

#define TRUE 1

#endif // GEELIB_H_
