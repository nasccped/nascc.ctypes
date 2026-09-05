/* MIT License
 * 
 * Copyright (c) 2026 nasccped
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "vector.h"
#include <stdlib.h>

// Minimum capacity when initializing a new vector.
#define VECTOR_MINIMUM_CAPACITY 1

typedef size_t usize;
typedef struct vector Vec;

void vector_deinit(Vec *v) {
  if (!v)
    return;

  else if (v->items)
    free(v->items);

  v->count = 0;
  v->capacity = 0;
  v->item_size = 0;
  v->items = NULL;
}

usize vector_init(Vec *v, usize item_size) {
  void **items;

  // invalid params
  if (!v || !item_size)
    return 0;

  // already initialized
  else if (v->capacity || v->count || v->items)
    return 0;

  // malloc fails
  else if (!(items = malloc(item_size * VECTOR_MINIMUM_CAPACITY)))
    return 0;

  v->count = 0;
  v->capacity = 1;
  v->item_size = item_size;
  v->items = items;

  return item_size;
}

