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

#ifndef _NASCC_CUSTOM_SIZED_ITEM_IMPL_H_
#define _NASCC_CUSTOM_SIZED_ITEM_IMPL_H_

#include "./custom_sized_item_def.h"

// This function takes a custom sized item struct and deinitialize it's inner fields. Does nothing
// if cs param refers to NULL.
void custom_sized_item_deinit(struct _custom_sized_item *cs);

// This function takes a custom sized item struct and initialize it's inner fields based on 'size'
// param.
//
// It'll allocate the required memory (but not set any data), update the 'size' inner field and
// then, return the allocated size.
//
// It'll return zero if either 'cs'/'size' refers to '0'/'NULL' respectively. Operation can also
// fail if an already initialized struct (you mus deinitilize it before).
size_t custom_sized_item_init(struct _custom_sized_item *cs, size_t size);

// Copies the data bytes into custom sized item struct inner data. Note that this function uses
// 'memcpy' and requires the 'size_t' refering as how many bytes to copy.
//
// This function returns a size_t value meaning the amount of bytes that was copied (taken from
// the self 'cs->size' field).
//
// The operation will fail if:
// - cs is null
// - cs isn't initialized (have no allocated memory. You must use custom_sized_item_init)
// - data is null
size_t custom_sized_item_set(struct _custom_sized_item *cs, void *data);

#endif
