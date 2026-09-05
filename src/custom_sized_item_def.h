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

#ifndef _NASCC_CUSTOM_SIZED_ITEM_DEF_H_
#define _NASCC_CUSTOM_SIZED_ITEM_DEF_H_

#include <stdlib.h>

// This struct refers to an item that memory size isn't know at compile time. It's an improvised
// way to allow C compiling generics throughout primitive and custom data types (such as unions and
// structs).
//
// This struct stores the size of value being held + the address to it's data. Anyway, this header
// doesn't implements it's features. Consider checking out the 'custom_sized_item_impl' files.
struct _custom_sized_item {
  size_t size;
  void *data;
};

#endif
