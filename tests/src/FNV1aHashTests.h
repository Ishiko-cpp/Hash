/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/hash/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_HASH_TESTS_FNV1AHASHTESTS_H_
#define _ISHIKO_HASH_TESTS_FNV1AHASHTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class FNV1aHashTests : public Ishiko::Tests::TestSequence
{
public:
    FNV1aHashTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void UpdateTest1(Ishiko::Tests::Test& test);
    static void UpdateTest2(Ishiko::Tests::Test& test);
    static void UpdateTest3(Ishiko::Tests::Test& test);
};

#endif
