/*
    Copyright (c) 2017-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Hash/blob/main/LICENSE.txt
*/

#include "SHA512Hash.h"
#include <fstream>

namespace Ishiko
{
namespace Hash
{

SHA512Hash::SHA512Hash()
{
}

void SHA512Hash::update(const char* data, size_t length)
{
    m_context.update((const uint8_t*)data, length);
}

void SHA512Hash::updateFromFile(const std::string& filePath)
{
    std::ifstream input(filePath.c_str(), std::ios_base::in | std::ios_base::binary);
    const size_t bufferSize = 10 * 1024;
    char buffer[bufferSize];
    while (input.read(buffer, bufferSize).good())
    {
        update(buffer, bufferSize);
    }
    if (!input.eof())
    {
        throw 0;
    }
    update(buffer, input.gcount());
}

const std::array<unsigned char, 64>& SHA512Hash::value() const
{
    m_context.final(m_value.data());
    return m_value;
}

}
}
