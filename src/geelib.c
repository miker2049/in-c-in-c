#include "geelib.h"
#include "cvector.h"

GPtrArray* g_ptr_array_new() {
  GPtrArray *out = malloc(sizeof(GPtrArray));
  out->len = 0;
  out->pdata = NULL;
  return out;
}

int g_ptr_array_remove(GPtrArray *arr, gpointer ptr) {
  uint i;
  int d = 0;
  /* g_return_val_if_fail(expr, val); */

  if(!arr)
    return 0;
  if(!(arr->len == 0 || (arr->len != 0 && arr->pdata != NULL)))
    return 0;

  if ((arr)) {
    for (i = 0; i < arr->len; ++i) {
      if (arr->pdata[i] == ptr) {
        /* g_message("%d  %d", (int)&arr[i], (int)ptr); */
        g_ptr_array_remove_index(arr, i);
        d = 1;
      }
    }
  }
  return d;
}
