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

#include "../../src/vector.h"
#include <assert.h>
#include <stdio.h>

// Default item size used for this test case.
#define ITEM_SIZE sizeof(int)

// Asserts de-initialized vector.
void assert_deinitialized(struct vector *v);

// Asserts initialized vector.
void assert_initialized(struct vector *v);

int main(void) {
  struct vector v = {0};

  assert_deinitialized(&v);

  // NOTE: returning zero means that the error occurred on 'vector_init' inner operation (probably
  //       'malloc' call). Later asserts are obviously useless since this one failed.
  if (!vector_init(&v, ITEM_SIZE)) {
    fprintf(stderr, "Vector initializing failed (%s: %d)\n", __FILE__, __LINE__ - 1);
    fprintf(stderr, "Aborting with error code!\n");
    return 1;
  }

  assert_initialized(&v);
  vector_deinit(&v);
  assert_deinitialized(&v);

  return 0;
}

void assert_deinitialized(struct vector *v) {
  assert(NULL != v);
  assert(0 == v->count);
  assert(0 == v->capacity);
  assert(0 == v->item_size);
  assert(NULL == v->items);
}

void assert_initialized(struct vector *v) {
  assert(NULL != v);
  assert(0 == v->count);
  assert(1 == v->capacity);
  assert(ITEM_SIZE == v->item_size);
  assert(NULL != v->items);
}
