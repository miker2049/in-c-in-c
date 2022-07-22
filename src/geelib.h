#ifndef GEELIB_H_
#define GEELIB_H_
#import "cvector.h"

typedef char gchar;
typedef void *gpointer;
typedef const gpointer gconstpointer;
typedef int guint;
typedef int gint;

typedef unsigned int uint;
typedef struct _GPtrArray GPtrArray;
struct _GPtrArray {
  gpointer *pdata;
  guint len;
};

GPtrArray *g_ptr_array_new(void);
int g_ptr_array_remove(GPtrArray *, gpointer);

#define g_error(...) printf(__VA_ARGS__)
#define g_message(...) printf(__VA_ARGS__)
#define g_critical(...) printf(__VA_ARGS__)
#define g_warning(...) printf(__VA_ARGS__)
#define g_debug(...) printf(__VA_ARGS__)
#define g_log_set_default_handler(...) NULL
#define GLogLevelFlags int

#define g_ptr_array_free(arr, b)                                               \
  do {                                                                         \
    cvector_free(arr->pdata);                                                  \
    free(arr);                                                                 \
  } while (0)

#define g_ptr_array_index(arr, idx) (arr->pdata)[idx]
#define g_ptr_array_add(arr, item)                                             \
  do {                                                                         \
    cvector_push_back(arr->pdata, item);                                       \
    arr->len += 1;                                                             \
  } while (0)

#define g_ptr_array_remove_index(arr, idx)                                     \
  do {                                                                         \
    cvector_erase(arr->pdata, (unsigned long)idx);                             \
    arr->len -= 1;                                                             \
  } while (0)

#define g_return_val_if_fail(expr, val)                                        \
  do {                                                                         \
    if (expr) {                                                                \
    } else {                                                                   \
      return (val);                                                            \
    }                                                                          \
  } while (0)

#endif // GEELIB_H_
