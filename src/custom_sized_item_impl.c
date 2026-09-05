#include "custom_sized_item_impl.h"
#include <string.h>

typedef struct _custom_sized_item CustomSized;
typedef size_t usize;

void custom_sized_item_deinit(CustomSized *cs) {
  // cs is null
  if (!cs)
    return;

  // non-null data
  if (cs->data) {
    free(cs->data);
    cs->data = NULL;
  }

  // zero size
  cs->size = 0;
}

usize custom_sized_item_init(CustomSized *cs, usize size) {
  void *data;

  // not allowed ptr/size
  if (!cs || !size)
    return 0;

  // already initialized
  else if (cs->size || cs->data)
    return 0;

  // allocation failed
  else if (!(data = malloc(size)))
    return 0;

  cs->data = data;
  cs->size = size;

  return size;
}

usize custom_sized_item_set(CustomSized *cs, void *data) {
  // null ptrs
  if (!cs || !data)
    return 0;

  // not initialized
  else if (!cs->size || !cs->data)
    return 0;

  // byte copy fails
  else if (!memcpy(cs->data, data, cs->size))
    return 0;

  return cs->size;
}
