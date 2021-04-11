/*
    Copyright (c) 2017-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Hash/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_HASH_SHA512HASH_H_
#define _ISHIKO_HASH_SHA512HASH_H_

#include <botan/sha2_64.h>
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
    /// Recomputes the value of the hash based on the contents of a file.
    /**
        This is equivalent to calling update with the contents of the file.
        @param filePath The path of the file whose contents will be read and used
          to update the value of the hash.
    */
    void updateFromFile(const std::string& filePath);
    /// Gets the current value of the hash based on the input data passed by the various update functions so far.
    /**
        @return A 512 bit array with the value of the hash.
        @see update
        @see updateFromFile
    */
    const std::array<unsigned char, 64>& value() const;

private:
    mutable Botan::SHA_512 m_context;
    mutable std::array<unsigned char, 64> m_value;
};

}
}

#include "linkoptions.h"

#endif
