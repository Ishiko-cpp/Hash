/*
    Copyright (c) 2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#ifndef _ISHIKO_HASH_SHA512HASH_H_
#define _ISHIKO_HASH_SHA512HASH_H_

#include <openssl/sha.h>
#include <array>

namespace Ishiko
{
namespace Hash
{

/// This class holds a SHA-512 hash and functions to update it.
class SHA512Hash
{
public:
    /// The constructor.
    SHA512Hash();

    /// Recomputes the value of the hash based on additional data.
    /**
        This function can be called multiple times to append more data each time.
        @param data Pointer to the start of the buffer containing the data.
        @param length Length of the buffer.
    */
    void update(const char* data, size_t length);
    void updateFromFile(const std::string& filePath);
    /// Gets the current value of the hash based on the input data passed by the update function so far.
    /**
        @return A 512 bit array with the value of the hash.
    */
    const std::array<unsigned char, 64>& value() const;

private:
    mutable SHA512_CTX m_context;
    mutable std::array<unsigned char, 64> m_value;
};

}
}

#include "linkoptions.h"

#endif
