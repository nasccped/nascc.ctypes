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

#ifndef _NASCC_VECTOR_H_
#define _NASCC_VECTOR_H_

#include <stdlib.h>

// Vector type abstraction. It holds self vector data, such as current capacity and item count.
// Also carries the size required by the element (which is used when new allocation is required).
struct vector {
  size_t count, capacity, item_size;
  void **items;
};

// Frees the vector inner memory (referring to item pointers) + put zeroes on counting fields. Does
// nothing if parameter points to null + only free when items not null.
void vector_deinit(struct vector *v);

// Initializes a vector struct instance. Note that it receives a pointer + size required by the item
// being held. This function returns a unsigned long long meaning the memory size that was alloc
// (or '0' if operation fails).
//
// Operation failing scenarios:
// - vector pointer is null
// - item_size is zero
// - vector was already initialized (contains non-(zero/null) fields) (must use 'vector_deinit' in
//   that case)
// - malloc's call returns null.
size_t vector_init(struct vector *v, size_t item_size);

#endif
